#ifndef MYPLC_H
#define MYPLC_H

#include <QString>
#include <QtWidgets>

// ---------------------------------------------------------------------------------------------
// F i r m w a r e  D e f s                                                          B O A R D S
// ---------------------------------------------------------------------------------------------
//
#define HW_NBV30      0x01 // Nanoboard V3 ( RMS Shield + Arduino Nano )
#define HW_ESP01      0x02 // Esp 8266 MyPlc Shield  ( !!! To bee )
#define HW_PC241      0x03 // Nanoboard PIC24xxxx  ( !!! To bee )
//
#define _VerByte(v,r)   (word_t)((v<<5)|(r&0x1F))
#define _ByteVer(b)     (word_t)(b>>5)
#define _ByteRel(b)     (word_t)(b&0x1F)
//
//
// ---------------------------------------------------------------------------------------------
// F i r m w a r e  D e f s                                          M O D U L E S  &  P O R T S
// ---------------------------------------------------------------------------------------------
//
//
#define ON   0x01           // Port value On ( +5V / Circuit closed ), Off ( 0V / Circuit open )
#define OFF  0x00
//
#define In    ON            // I/O port data direction In/Out
#define Out   OFF
//
#define Act   ON            // Controlled device  (1 Act - Actuator )  ( 0 Sns - Sensor )
#define Sns   OFF


typedef unsigned short word_t;              // short unsigned int

typedef enum : word_t
             {
               _NODEF = 0x00,      // Undefined
               _NBV30 = 0x01,      // Nanoboard 3.0
               _SEM16 = 0x02,      // Sem16 SPI I/O Expander
               _LCNIF = 0x03       // Loconet Interface
             } module_t;

typedef word_t  port_t;         // 16bit Port
typedef word_t  maddr_t;        // Hardware address ( SPI, i2c, etc... )
typedef word_t  saddr_t;        // Port sub-address ( 10bit )
typedef word_t  flag_t;         // smaller data only one bit
typedef word_t  idx_t;          // Port/Module index in array


// ---------------------------------------------------------------------------------------------
// F i r m w a r e  D e f s                                        S E R I A L  P R O T O C O L
// ---------------------------------------------------------------------------------------------
//
//
typedef enum : word_t {
    _INFO     = 0x00,         // uC -> PC, info about device ( IDatas )
    _RETRIEVE = 0x01,         // PC -> uC, uC send back CDatas
    _REWRITE  = 0x02,         // PC -> uC, follow CDatas, uC send back ACK infos
    _MODULE   = 0x03,         // Module datas ( used by _RETRIEVE / _REWRITE )
    _PORT     = 0x04,         // Port datas
    _RULE     = 0x05,         // Rule datas
    _COMPLETE = 0x06          // Data exchange finished
               } _vs_cmd_t;


typedef struct {            // ___________10 Words _INFO
    word_t hardware;        // Board type
    word_t firmware;        // Firmware (vvv.rrrrr)
    word_t serial;          //
    word_t memory;          // Available memory (Kbits)
    word_t eprom;           // Available eeprom (Kbits)
    word_t cycle;           // Cycle time (ms)
                            //
    word_t modules;         // n Modules
    word_t p_in;            // n In Ports
    word_t p_out;           // n Out Ports
    word_t rules;           // n Rules
               } vs_info_t;


typedef struct {            // ___________3 Words _MODULE
    word_t idx;             // uC Array Index
    word_t mtype;           // 4 bits type / 4 bits opts
    word_t maddr;
    word_t mopts;
               } vs_module_t;


typedef struct {            // ___________6 Words  _PORT
    word_t idx;             // uC Array Index
    word_t imod;
    word_t paddr;           // * key field ( subaddr )
    word_t io;
    word_t ptype;
    word_t defval;
               } vs_port_t;


typedef struct {            // ____________6 Words _RULE
    word_t idx;             // uC Array Index
    word_t rl;              // Condition/Expression
    word_t ipev;            // index In port ( Evaluation Port )
    word_t ipac;            // index Out port ( Action Port )
               } vs_rule_t;


typedef struct {            // _____________ Commands
     word_t mode;
     word_t nmo;            // rule condition coding
     word_t npi;            // index innput port
     word_t npo;            // index output port
     word_t nrl;
               } vs_rewrite_t;

#define _VS_REWRITE_BEGIN    1  // OPT BEGIN
#define _VS_REWRITE_END      0  // OPT END



typedef union {              // config opt raw data
      vs_info_t device;
    vs_module_t module;
      vs_port_t port;
      vs_rule_t rule;
              } syncdata_t;


// Packet

typedef struct {                // Fix size Packet Model
  _vs_cmd_t cmd;                // 2 bytes
    union {         // SYNCDATA_T
        vs_module_t module;
          vs_port_t port;
          vs_rule_t rule;
          vs_info_t info;       // ________20 bytes
       vs_rewrite_t rewrite;    // vc_cmdopt_t  opt
          };
               } vs_pkt_t;

#define _VS_PKT_SIZE        22  // _VS_PKT_SIZE
#define _VS_OPT_ERROR        5  // OPT ERROR



// ---------------------------------------------------------------------------------------------
//                                                      M Y P L C    V I R T U A L   D E V I C E
// ---------------------------------------------------------------------------------------------
//
//


typedef enum {
        DEVICE,             // Root
        MODULE,
        PORT,
        RULE
             } itemtype_t;        // DATA ELEMENT TYPE


typedef struct {
    itemtype_t type;              // element type
      QString alias;              // description (local)
         bool enable;             // enabled (valid to exchage...)
         bool sync;               // in-sync (received/trasferred...)

        union {        // SYNCDATA_T           // config opt raw data
              vs_info_t device;
            vs_module_t module;
              vs_port_t port;
              vs_rule_t rule;
              };

               } itemdata_t;       // CONFIG DATA ELEMENT


Q_DECLARE_METATYPE(itemdata_t);


#define ITEM_NCOLUMNS   14

                            // META DATA:
#define I_TYPE          0       // Element type
#define I_ALIAS         1       // Text alias
#define I_ENAB          2       // Enable/Disable item
#define I_SYNC          3       // uC Syncronized

                            // Element's Coulumns defs:
#define IE_IDX          4   // uC index

                            // Module & Ports
#define IE_TYPE         5       // Module/port type
#define IE_ADDR         6       // maddr/saddr

                                // Module:
#define IE_NPORT        7       // number of ports
#define IE_MOPT1        8       // Hw option1
#define IE_MOPT2        9       // Hw option2

                                // Port:
#define IE_IO           7       // port I/O
#define IE_DVAL         8       // port default value
#define IE_MIDX         9       // port module idx ref

                            // Rule
#define IE_RLC          5      // Rule condition/action
#define IE_IPEV         6      // Rule Idx Port to evaluate    (PIn)
#define IE_IPCH         7      // Rule Idx Port to act/change  (POut)

                            // DEVICE DATA
#define ID_SERIAL       4
#define ID_FIRMWARE     5
#define ID_HARDWARE     6
#define ID_CYCLE        7
#define ID_MEMORY       8
#define ID_EEPROM       9
#define ID_MODULES      10
#define ID_INPORTS      11
#define ID_OUTPORTS     12
#define ID_RULES        13
#define ID_PORTS        14




// Store MyPlc configutration
//
class myplcItem
{
public:
    explicit myplcItem(const itemdata_t &opt, myplcItem *parent = nullptr);
    ~myplcItem() { qDeleteAll(m_childs); }

                     // used by Model
                void appendChild(myplcItem *child);
           myplcItem *child(int row);
                 int childCount() const;            // Number of child items
                 int columnCount() const;           // Number of fields
            QVariant data(int nfield) const;
                 int row() const;                   // Item row number in model
    inline myplcItem *parent() { return (m_parent); }

                     // used by Device
          itemdata_t getItemData();
                void setItemData(itemdata_t &data);
           myplcItem *getItemModule(word_t idx);
           myplcItem *getItemPort(word_t imodule, word_t paddr);
           myplcItem *getItemRule(word_t idx);
          itemtype_t itemType() { return (m_data.type); }

private:
    myplcItem *m_parent;
    QVector<myplcItem*> m_childs;
    itemdata_t m_data;  // optdata
};



// Implement data mantainance and exchange

class MyPlcDevice: public QObject
{
    Q_OBJECT

public:
    MyPlcDevice(const QString &alias);
    ~MyPlcDevice() { }

    myplcItem *getDeviceItems() { return (m_device); }       // Used by DataModels
          int itemCount() { return (10); }              // Used by serial pBar

  private:
    void addNewItem(const itemdata_t &opt);

public slots:

    bool syncIsDevice(const vs_info_t &rawdev) {return false;}  // Check device data (Hw,Sf,Serial...)
    void syncComplete(bool l_rwcmd) { emit deviceChanged(); }
    bool updateItem(const itemdata_t &opt);                      // sync local Item received from serial

    bool inSync() { return (true); }        // check enabled Items and return "and-ed" sync fileds
    void load() {}                          // Load data items from file
    void save() {}                          // Save local data to file

  signals:
    void deviceChanged();

private:
    myplcItem *m_device;                // First device's items
    //QString  m_filename = "";           // Device's filename
    //int itemcounter=0;
};


#endif // MYPLC_H




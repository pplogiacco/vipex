#ifndef MYPLC_H
#define MYPLC_H

#include <QString>
#include <QtWidgets>


// ---------------------------------------------------------------------------------------------
// F i r m w a r e  D e f s                                          M O D U L E S  &  P O R T S
// ---------------------------------------------------------------------------------------------
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
               _NODEF = 0x00,
               _NBV30 = 0x01,      // Nanoboard 3.0
               _SEM16 = 0x02,      // Sem16 SPI I/O Expander
               _LCNIF = 0x03       // Loconet Interface
             } module_t;


typedef word_t  port_t;         // 16bit Port
typedef word_t  maddr_t;        // Hardware address ( SPI, i2c, etc... )
typedef word_t  saddr_t;        // Port sub-address ( 10bit )
typedef word_t  flag_t;         // smaller data only one bit
typedef word_t  idx_t;          // Port/Module index in array

                                    // Nanoboard V3.0 Pinout
#define NB_GPIO1        16          // A2
#define NB_GPIO2        17          // A3
#define NB_GPIO3         3          // D3
#define NB_GPIO4         4          // D4
#define NB_GPIO5         7          // D7
#define NB_GPIO6         9          // D9
#define NB_GPIO7        20          // A6
#define NB_GPIO8        21          // A7



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
               } _vs_cmd_t;

typedef struct {            // ___________10 Words _INFO  ( IDatas )
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

typedef struct {            // ___________6 Words  _PORT
    word_t idx;             // uC Array Index
    word_t imodule;
    word_t subaddr;         // * key field
    word_t io;
    word_t ptype;
    word_t defval;
               } vs_port_t;

typedef struct {            // ___________3 Words _MODULE
    word_t idx;             // uC Array Index
    word_t mtype;
    word_t addr;
               } vs_module_t;

typedef struct {            // ____________6 Words _RULE
    word_t idx;             // uC Array Index
    word_t rl;              // Condition/Expression
    word_t pin;             // index In port ( Evaluation Port )
    word_t pout;            // index Out port ( Action Port )
               } vs_rule_t;

typedef struct {
     word_t mode;
     word_t nmo;            // rule condition coding
     word_t npi;            // index innput port
     word_t npo;            // index output port
     word_t nrl;
               } vs_rewrite_t;

#define _VS_REWRITE_BEGIN    1  // OPT BEGIN
#define _VS_REWRITE_END      0  // OPT END

typedef struct {                // Fix size Packet Model
  _vs_cmd_t cmd;                // 2 bytes
    union {
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

/*
#define MAX_PxNBV30      8          // NBV30 module port number
//
#define MAX_PxSEM16     16          // SEM16..
//
#define MAX_PxLCNIF     32          // LCNIF
//
#define MAX_MxD          8          // Max modules in device
#define MAX_PxM         16          // Max ports in module ( Static declaration.. TO BE FIX to dynamic.. )
#define MAX_RULES       36          // Max rules in device
#define ALIAS_LEN       21


typedef int v_idx_t ;

typedef struct {
   v_idx_t  idx;
      char  palias[ALIAS_LEN];      // Alias lenght 20 char
      bool  enabled;
    word_t  io;
    word_t  subaddr;
    word_t  ptype;
    word_t  defval;
               } v_port_t;

typedef struct {
   v_idx_t  idx;
      char  malias[ALIAS_LEN];      // Alias lenght 20 char
      bool  enabled;
  module_t  mtype = _NODEF;
    word_t  addr;
    word_t  nports;
  v_port_t  ports[MAX_PxM];         // Max 16 ports/module
               } v_module_t;

typedef struct {
   v_idx_t  idx;
    word_t  imodule;                // condition
    word_t  iport;                  // index in port
               } v_rport_t;

typedef struct {
   v_idx_t  idx;
      char  ralias[ALIAS_LEN];      // rule's alias
      bool  enabled;
    word_t  rl;                     // condition
 v_rport_t  pi;                     // in port
 v_rport_t  po;                     // out port

               } v_rule_t;

typedef struct {
    word_t  nmo;
    word_t  npi;                    //
    word_t  npo;                    //
    word_t  nrl;                    //
               } v_wdatas_t;



typedef struct {                    // Device:
         vs_info_t info;                // IDatas
              char dalias[ALIAS_LEN];
              char filename[ALIAS_LEN];

             idx_t nModules=0;
        v_module_t modules[MAX_MxD];    // CDatas

             idx_t nRules=0;
          v_rule_t rules[MAX_RULES];

        v_wdatas_t wdatas;
               } v_device_t;



class MyPlc //: QObject
{

 //   Q_OBJECT

//signals:
//     void myplcChanged();

public:

    MyPlc() = default;
    ~MyPlc() = default;

    //MyPlc(const MyPlc &) = default;
    //MyPlc &operator=(const MyPlc &) = default;

     void setMyPlc(v_device_t *dev);            // Called by file's routines
   inline const v_device_t* getMyPlc() { return (&device); }

     bool setInfo(vs_info_t *info);             // Called by serial's routines
   inline vs_info_t* getInfo() { return (&device.info); } // Used by UI

     bool updateModule(vs_module_t *module);    // search by type & addr set idx
     bool updatePort(vs_port_t *port);          // by idx
     bool updateRule(vs_rule_t *rule);          // by idx

     bool rebuild();                              // Rebuild Device's datas
     void clean();
     v_device_t  device;        // Configuration datas

private:
     void addWiringModule(word_t mtype, word_t addr, word_t midx = 0);
     bool rebuildRule(v_rule_t *rule );

     char *eeprom = nullptr;
     int  esize = 0;
     bool insync = false;       // Different data Pc<->uC (idx)
     bool isinit = false;

};

*/
// Q_DECLARE_METATYPE(MyPlc)

#endif // MYPLC_H




#include <stdio.h>
#include <string.h>
#include "myplc.h"



#define _NBV30_NPORTS    8       // Nanoboard 3.0
#define _SEM16_NPORTS    16      // Sem16 SPI I/O Expander
#define _LCNIF_NPORTS    32      // Loconet Interface

#define _MOpt1(o) ( o    & 0xF )
#define _MOpt2(o) ( o>>4 & 0xF )

word_t _NBV30PINS[] =
       {16,17,3,4,7,9,20,21};       // Pins: A2,A3,D3,D4,D7,D9,A6,A7



myplcItem::myplcItem(const itemdata_t &opt, myplcItem *parent)
    : m_parent(parent),
      m_data(opt)

{
      itemdata_t nport;
      int i;

      switch ( m_data.type ) {

         case DEVICE:
               return;

         case MODULE:
              switch ( m_data.module.mtype ) {

                case _NBV30:
                  m_data.alias = QString("Nanoboard v3.0 (USB)");  // Later
                  nport.type = PORT;
                  nport.enable = false;
                  nport.sync = false;
                  nport.port.idx = 0; // static_cast<word_t>(i);
                  nport.port.imod = m_data.module.idx;
                  nport.port.ptype = 0;
                  nport.port.defval = 0;
                  nport.port.io = 0;

                  for(i=0; i< _NBV30_NPORTS; i++)
                  {
                   nport.alias = QString("P%1").arg(i);
                   nport.port.paddr=_NBV30PINS[i];
                   appendChild(new myplcItem(nport,this));
                  }
                 return;

                case _SEM16:

                  m_data.alias = QString("Sem16 - IO Expander (%1)").arg(m_data.module.maddr);  // Later

                  nport.type = PORT;
                  nport.enable = false;
                  nport.sync = false;
                  nport.port.idx = 0; // static_cast<word_t>(i);
                  nport.port.imod = m_data.module.idx;
                  nport.port.ptype = 0;
                  nport.port.defval = 0;
                  nport.port.io = 0;

                  for(i=0; i<_SEM16_NPORTS; i++)
                  {
                   nport.alias = QString("P%1%2").arg((i<8)?"A":"B").arg((i>7)?i-8:i);
                   nport.port.paddr=static_cast<word_t>(i);
                   appendChild(new myplcItem(nport,this));
                  }
                 return;

                case _LCNIF:
                  m_data.alias = QString("Loconet-IF %2 (%1)").arg(opt.module.maddr).arg((_MOpt1(m_data.module.mopts))?"STA":"DEC");  // Later
              }  // end-switch
              return;

         case PORT:
              return;

         case RULE:
              return;

      }  // end-switch

};


 // x DataModel

myplcItem *myplcItem::child(int number)
 {
     if (number < 0 || number >= m_childs.size())
         return nullptr;
     return m_childs.at(number);
 }

void myplcItem::appendChild(myplcItem *item)
{
    m_childs.append(item);
}

int myplcItem::childCount() const
  {
      return m_childs.count();
  }

int myplcItem::row() const
{
    if (m_parent)
        return m_parent->m_childs.indexOf( const_cast<myplcItem*>(this) );  // Pos in parent's child array
    return 0;
}

int myplcItem::columnCount() const
{
    switch ( m_data.type ) {   // Return columns for opt type
       case DEVICE:
            return (14); // vs_info_t
       case MODULE:
            return (9);  // vs_module_t + metadata ( Type, Alias, Enabled, Sync )
       case PORT:
            return (9);  // vs_module_t + metadata ( Type, Alias, Enabled, Sync )
       case RULE:
            return (7);  // vs_module_t + metadata ( Type, Alias, Enabled, Sync )
    }  // end-switch

     return (0);// m_data.count();
 }

QVariant myplcItem::data(int nfield) const
 {
    if (nfield >= 0 ) {

        if ( nfield < 4  ) {   // metadata ( Type, Alias, Enabled, Sync )
            switch ( nfield) {
               case I_TYPE:
               return (m_data.type);       // Element type
               case I_ALIAS:
               return (m_data.alias);      // Text alias
               case I_ENAB:
               return (m_data.enable);     // Enable/Disable item
               case I_SYNC:
               return (m_data.sync);       // uC Syncronized
            }  // end-switch

        } else {

        switch ( m_data.type ) {   // Return columns for opt type

           case DEVICE:
                switch ( nfield ) {   // vs_info_t
                case ID_SERIAL:
                       return (m_data.device.serial);
                case ID_FIRMWARE:
                       return (m_data.device.firmware);
                case ID_HARDWARE:
                       return (m_data.device.hardware);
                case ID_CYCLE:
                       return (m_data.device.cycle);
                case ID_MEMORY:
                       return (m_data.device.memory);
                case ID_EEPROM:
                       return (m_data.device.eprom);
                case ID_MODULES:
                       return (m_data.device.modules);
                case ID_PORTS:
                       return (m_data.device.p_out+ m_data.device.p_in);
                case ID_RULES:
                       return (m_data.device.serial);
                case ID_INPORTS:
                       return (m_data.device.p_in);
                case ID_OUTPORTS:
                       return (m_data.device.p_out);
                }  // end-switch
                break;

           case MODULE:
                switch ( nfield ) {   // vs_module_t
                case IE_IDX:
                        return (m_data.module.idx);        // uC index
                case IE_TYPE:
                        return (m_data.module.mtype);      // Module type
                case IE_ADDR:
                        return (m_data.module.maddr);      // maddr
                case IE_NPORT:
                        switch ( m_data.module.mtype ) {   // number of ports
                           case _NBV30:
                                return (_NBV30_NPORTS);
                           case _SEM16:
                                return (_SEM16_NPORTS);
                           case _LCNIF:
                                return (_LCNIF_NPORTS);
                        }  // end-switch
                        break;
                case IE_MOPT1:
                        break;     // Hw option1
                case IE_MOPT2:
                        break;     // Hw option2
                }  // end-switch
                break;

           case PORT:
                switch ( nfield ) {   // vs_port_t
                case IE_IDX:
                    return (m_data.port.idx);        // uC index
                case IE_TYPE:
                    return (m_data.port.ptype);      // Module type
                case IE_ADDR:
                    return (m_data.port.paddr);      // maddr
                case IE_IO:
                    return (m_data.port.io);         // port I/O
                case IE_DVAL:
                    return (m_data.port.defval);     // port default value
                case IE_MIDX:
                    return (m_data.port.imod);       // port module idx ref
                }  // end-switch
                break;

           case RULE:
                switch ( nfield ) {   // vs_rule_t
                case IE_IDX:
                    return (m_data.rule.idx);        // uC index
                case IE_RLC:
                    return (m_data.rule.rl);      // Rule condition/action
                case IE_IPEV:
                    return (m_data.rule.ipev);      // Rule Idx Port to evaluate    (PIn)
                case IE_IPCH:
                    return (m_data.rule.ipac);      // Rule Idx Port to act/change  (POut)
                }  // end-switch
                break;

        }  // end-switch
        }

    }
    return QVariant();  // no valid nfield specified
}



// x Device

itemdata_t myplcItem::getItemData()
{
   return (m_data);
};

void myplcItem::setItemData(itemdata_t &data)
{
    m_data = data;
};

myplcItem *myplcItem::getItemModule(word_t idx)
{
    if ( m_data.type == DEVICE )
    {
    int i = childCount();
    while ( i>0 && (child(i-1)->itemType()==MODULE) && (child(i-1)->getItemData().module.idx != idx) ) i--;
    if (i>0)
        return (child(i-1));
    }
    return (nullptr);
};

myplcItem *myplcItem::getItemPort(word_t imodule, word_t paddr)
{
    if ( m_data.type == DEVICE )
    {
    int i = childCount();
    while ( (i>0) && (child(i-1)->itemType()==MODULE) && (child(i-1)->getItemData().module.idx != imodule)  ) i--;
     if (i>0)
     {
       int j = child(i-1)->childCount();
        while ( j>0 && (child(i-1)->child(j-1)->getItemData().port.paddr != paddr) ) j--;
        if (j>0)
            return (child(i-1)->child(j-1));
     }
    }
    return (nullptr);
};

myplcItem *myplcItem::getItemRule(word_t idx)
{
    if ( m_data.type == DEVICE )
    {
    int i = childCount();
    while ( (i>0) && (child(i-1)->itemType()==RULE) && (child(i-1)->getItemData().rule.idx != idx) ) i--;
    if (i>0)
        return (child(i-1));
    }
    return (nullptr);
};




/*  NON UTILIZZATI DA ELIMARE !!!
bool myplcItem::setData(int nfield, const QVariant &value)
  {

    if (nfield >= 0 ) {

        if ( nfield < 4  ) {   // metadata ( Type, Alias, Enabled, Sync )
            switch (nfield) {
               case I_TYPE:
               m_data.type =  static_cast<itemtype_t>(value.toInt());      // Element type
               return (true);
               case I_ALIAS:
               m_data.alias = value.toChar();      // Text alias
               return (true);
               case I_ENAB:
               m_data.enable = value.toBool();    // Enable/Disable item
               return (true);
               case I_SYNC:
               m_data.sync = value.toBool();   // uC Syncronized
               return (true);
            }  // end-switch

        } else {

        switch ( m_data.type ) {   // Return columns for opt type

           case DEVICE:
                switch ( nfield ) {   // vs_info_t
                case ID_SERIAL:
                       m_data.device.serial = static_cast<word_t>(value.toInt());
                       return (true);
                case ID_FIRMWARE:
                       m_data.device.firmware=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_HARDWARE:
                       m_data.device.hardware=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_CYCLE:
                       m_data.device.cycle=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_MEMORY:
                       m_data.device.memory=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_EEPROM:
                       m_data.device.eprom=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_MODULES:
                       m_data.device.modules=static_cast<word_t>(value.toInt());
                       return (true);
                case ID_PORTS:
                       break;
                case ID_RULES:
                       m_data.device.rules = static_cast<word_t>(value.toInt());
                       return (true);
                case ID_INPORTS:
                       m_data.device.p_in = static_cast<word_t>(value.toInt());
                       return (true);
                case ID_OUTPORTS:
                       m_data.device.p_out= static_cast<word_t>(value.toInt());
                       return (true);
                }  // end-switch
                break;

           case MODULE:
                switch ( nfield ) {   // vs_module_t
                case IE_IDX:
                        m_data.module.idx= static_cast<word_t>(value.toInt());        // uC index
                        return(true);
                case IE_TYPE:
                        m_data.module.mtype =static_cast<module_t>(value.toInt());    // Module type
                        return (true);
                case IE_ADDR:
                        m_data.module.maddr=static_cast<word_t>(value.toInt());       // maddr
                        return (true);
                case IE_NPORT:
                        break;
                case IE_MOPT1:
                        break;     // Hw option1
                case IE_MOPT2:
                        break;     // Hw option2
                }  // end-switch
                break;

           case PORT:
                switch ( nfield ) {   // vs_port_t
                case IE_IDX:
                    m_data.port.idx= static_cast<word_t>(value.toInt());        // uC index
                    return(true);
                case IE_TYPE:
                    m_data.port.ptype= static_cast<word_t>(value.toInt());     // Module type
                    return (true);
                case IE_ADDR:
                    m_data.port.paddr= static_cast<word_t>(value.toInt());
                    return (true);// maddr
                case IE_IO:
                    m_data.port.io = static_cast<word_t>(value.toInt());        // port I/O
                    return (true);
                case IE_DVAL:
                    m_data.port.defval= static_cast<word_t>(value.toInt());     // port default value
                    return (true);
                case IE_MIDX:
                    m_data.port.imod= static_cast<word_t>(value.toInt());       // port module idx ref
                    return (true);
                }  // end-switch
                break;

           case RULE:
                switch ( nfield ) {   // vs_rule_t
                case IE_IDX:
                    m_data.rule.idx= static_cast<word_t>(value.toInt());        // uC index
                    return(true);
                case IE_RLC:
                    m_data.rule.rl= static_cast<word_t>(value.toInt());        // Rule condition/action
                    return (true);
                case IE_IPEV:
                    m_data.rule.ipev=  static_cast<word_t>(value.toInt());       // Rule Idx Port to evaluate    (PIn)
                    return (true);
                case IE_IPCH:
                    m_data.rule.ipch= static_cast<word_t>(value.toInt());       // Rule Idx Port to act/change  (POut)
                    return (true);
                }  // end-switch
                break;

        }  // end-switch
        }

    }
    return (false);  // not updating

  }


void myplcItem::deleteAllChild()
{
  qDeleteAll(m_childs);
}

bool myplcItem::updateItem(const itemdata_t &opt)
{
    if ( m_data.type == PORT && opt.type == PORT && m_data.port.paddr == opt.port.paddr )
    {
      m_data.port = opt.port;
      return (true);
    }
    return (false);
}


void myplcItem::syncData(const itemdata_t &opt)
{
   m_data = opt;
}
*/


// ---------------------------------------------------------------------------------------
//// DEVICE !!!!
// ---------------------------------------------------------------------------------------

MyPlcDevice::MyPlcDevice(const QString &alias)
{
    itemdata_t itemdevice;
    itemdevice.type = DEVICE;
    itemdevice.alias = alias;
    itemdevice.sync = false;
    itemdevice.enable = false;

    itemdevice.device.hardware = 0;
    itemdevice.device.firmware = 0;
    itemdevice.device.serial = 0;
    itemdevice.device.modules = 0;
    itemdevice.device.p_in = 0;
    itemdevice.device.p_out = 0;
    itemdevice.device.rules = 0;

    m_device = new myplcItem(itemdevice);
}

void MyPlcDevice::addNewItem(const itemdata_t &opt)
{

    myplcItem *pmodule;

    switch ( opt.type ) {

       case DEVICE:
            break;

       case MODULE:

            m_device->appendChild(new myplcItem(opt,m_device));
            //emit deviceChanged();

              // do specific
              switch ( opt.module.mtype ) {
                case _NBV30:
                 break;
                case _SEM16:
                 break;
                case _LCNIF:
                 break;
               }

            break;

       case PORT:             // Find port and update, value enable and sync

            pmodule = m_device->getItemModule(opt.port.imod);
            if (pmodule)
            {
                pmodule->appendChild(new myplcItem(opt,pmodule));
            //    emit deviceChanged();
            }
            break;

       case RULE:
            m_device->appendChild(new myplcItem(opt,m_device));
            // emit deviceChanged();
            break;

    }  // end-switch
}


bool MyPlcDevice::updateItem(const itemdata_t &opt)     // SYNCDATA_T
{
    itemdata_t device;
     myplcItem *pmodule;
     myplcItem *pport;
     myplcItem *prule;

    switch ( opt.type ) {

       case DEVICE:
            //clear and xc   update first record
            device = m_device->getItemData();
            // do updates....
            device.device = opt.device;
            device.enable = opt.enable;
            m_device->setItemData(device);
            //emit deviceChanged();
            return (true);

       case MODULE:
            pmodule = m_device->getItemModule(opt.module.idx);
            if (pmodule)
            {
               itemdata_t module = pmodule->getItemData();  // get stored data
              // do updates
               module.module = opt.module;
               module.enable = opt.enable;
               // module.sync = false; NOT USED TO CHECK MODULE SYNC.. "AND" OF PORT SYNC...

              switch ( opt.module.mtype ) {
                case _NBV30:
                 break;

                case _SEM16:
                 break;

                case _LCNIF:
                 break;
              }

              pmodule->setItemData(module);

            } else { addNewItem(opt); }  // add modules

            //emit deviceChanged();
            return (true);

       case PORT:             // Find port and update, value enable and sync
            pport = m_device->getItemPort(opt.port.imod,opt.port.paddr);
            if (pport)
            {
                itemdata_t port = pport->getItemData(); // get local data
                port.enable = true;
                port.sync = true;
                // do updates
                port.port= opt.port;
                pport->setItemData(port);
                //emit deviceChanged();
                return (true);
            }
            break;

       case RULE:
            prule = m_device->getItemRule(opt.rule.idx);
            if (prule)
            {
                itemdata_t rule = prule->getItemData();
                // do updates
                rule.rule = opt.rule;
                rule.enable = true;
                rule.sync = true;

                prule->setItemData(rule);
                //emit deviceChanged();
                return (true);
            }
            break;

    }  // end-switch

  return (false);
}


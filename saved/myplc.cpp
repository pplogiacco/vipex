#include <stdio.h>
#include <string.h>
#include "myplc.h"



bool MyPlc::setInfo(vs_info_t *info)
{
    if ( isinit )  // hardware, firmware, serial 6 byte unique identifier....
    {
        word_t *p1 = (word_t *)&device.info;
        word_t *p2 = (word_t *)info;
        unsigned int i = sizeof(vs_info_t);
        i=i<<1;
        while ( i > 0 && ( *(p1+i) == *(p2+i) ) )  { i--; } // no check hardware
        insync = (i)?false:true;
    }
    else isinit = true;

    memcpy(&device.info, info, sizeof(vs_info_t));

/*  device.info.hardware = info->hardware;
    device.info.firmware = info->firmware;
    device.info.serial   = info->serial;
    device.info.memory   = info->memory;
    device.info.eprom    = info->eprom;
    device.info.cycle    = info->cycle;
    device.info.modules  = info->modules;
    device.info.p_in     = info->p_in;
    device.info.p_out    = info->p_out;
    device.info.rules    = info->rules; */
    return (true);
};


void MyPlc::setMyPlc(v_device_t *dev)
{
    memcpy(&device, dev, sizeof(v_device_t));
};


/*
bool MyPlc::updateModule(vs_module_t *module)
{
    idx_t i=0;
    while ( (i<device.nModules) && ( device.modules[i].idx != module->idx ) ) {i++; }
    //while ( (i<device.nModules) && ( device.modules[i].idx == i ) ) i++;
    if (device.modules[i].idx != device.modules[i].idx)  {
    //if (i<device.nModules)  {
      addWiringModule(module->mtype,module->addr);  // set idx !!!!!
      return (false);
    }
   return (true);
};
*/

void MyPlc::clean()
{
    device.nModules = 0;
    device.nRules = 0;
}



bool MyPlc::updateModule(vs_module_t *module)
{
    idx_t i=0;
    while ( (i<device.nModules) &&
            !( device.modules[i].mtype == module->mtype && device.modules[i].addr == module->addr ) ) {i++;}

    if (device.modules[i].mtype != module->mtype && device.modules[i].addr != module->addr) {
       addWiringModule(module->mtype,module->addr,module->idx);
       return (false);
    }
  device.modules[i].idx = module->idx;
  //emit myplcChanged();
  return (true);
}


bool MyPlc::updatePort(vs_port_t *port)
{
    int imod = port->imodule;
    int i = 0;
     if (imod<device.nModules) {
        while (i<device.modules[imod].nports && device.modules[imod].ports[i].subaddr != port->subaddr ) { i++; }
          if ( device.modules[imod].ports[i].subaddr == port->subaddr) {
              device.modules[imod].ports[i].idx = port->idx;
              device.modules[imod].ports[i].io = port->io;
              device.modules[imod].ports[i].ptype = port->ptype;
              device.modules[imod].ports[i].defval = port->defval;
              device.modules[imod].ports[i].enabled = 1;

             return (true);
          } else {
           // addnew port
          }
     }
    return (false);
};


bool MyPlc::updateRule(vs_rule_t *rule)
{

    // vs_rule_t:
    //      idx
    //      rl
    //      pin
    //      pout


    // cerca regola corrispondente:

    // v_rule_t:
    // idx
    // rl
    //
    // pi.idx
    // pi.imodule
    // pi.iport
    //
    // po.idx
    // po.imodule
    // po.iport
    // alias
    // enabled = true
return (true);

};


void MyPlc::addWiringModule(word_t mtype, word_t addr, word_t midx)
{
    word_t i;
    std::string str;

    device.modules[device.nModules].idx=midx;
    device.modules[device.nModules].addr= addr;
    device.modules[device.nModules].mtype= (module_t) mtype;
    device.modules[device.nModules].enabled = OFF;

    switch (device.modules[device.nModules].mtype) {
       case _NBV30:
            device.modules[device.nModules].nports=MAX_PxNBV30;
            strcpy_s(device.modules[device.nModules].malias,"Nanoboard v3");
            device.modules[device.nModules].ports[0].subaddr =  NB_GPIO1;
            device.modules[device.nModules].ports[1].subaddr =  NB_GPIO2;
            device.modules[device.nModules].ports[2].subaddr =  NB_GPIO3;
            device.modules[device.nModules].ports[3].subaddr =  NB_GPIO4;
            device.modules[device.nModules].ports[4].subaddr =  NB_GPIO5;
            device.modules[device.nModules].ports[5].subaddr =  NB_GPIO6;
            device.modules[device.nModules].ports[6].subaddr =  NB_GPIO7;
            device.modules[device.nModules].ports[7].subaddr =  NB_GPIO8;
            for( i = 0; i< device.modules[device.nModules].nports; i++ ) {
                strcpy_s(device.modules[device.nModules].ports[i].palias,
                        QString("Morsetto P%1 (uC%2)").arg(i).arg(device.modules[device.nModules].ports[i].subaddr).toLocal8Bit().constData());

            } // end
           break;

       case _SEM16:
            device.modules[device.nModules].nports=MAX_PxSEM16;
            strcpy_s(device.modules[device.nModules].malias,"Sem16-IOExpander");
            for( i = 0; i< device.modules[device.nModules].nports; i++ ) {

                device.modules[device.nModules].ports[i].subaddr = i;    // 0..7 "A", 8..15 "B"
                strcpy_s(device.modules[device.nModules].ports[i].palias,
                     QString("Port %1%2 (%3)").arg((i<8)?"A":"B").arg((i<8)?i:i-8).arg(i).toLocal8Bit().constData());
            } // end

           break;

       case _LCNIF:
            device.modules[device.nModules].nports=MAX_PxLCNIF;
            strcpy_s(device.modules[device.nModules].malias,"Loconet-IF");

            for( i = 0; i< device.modules[device.nModules].nports; i++ ) {
             device.modules[device.nModules].ports[i].subaddr = i;
             strcpy_s(device.modules[device.nModules].ports[i].palias,
                  QString("Indirizzo Loconet").toLocal8Bit().constData());
            } // end

           break;
    }  // end-switch

    for( i = 0; i< device.modules[device.nModules].nports ; i++ ) {
        device.modules[device.nModules].ports[i].io = In;
        device.modules[device.nModules].ports[i].enabled = OFF;
        device.modules[device.nModules].ports[i].defval = OFF;
        device.modules[device.nModules].ports[i].ptype = Sns;
    } // end
    device.nModules++;
}



bool MyPlc::rebuildRule(v_rule_t *rule )
{
  bool ret = true;

   ret &= device.modules[rule->pi.imodule].ports[rule->pi.iport].enabled;
   rule->pi.idx = device.modules[rule->pi.imodule].ports[rule->pi.iport].idx;

   ret &= device.modules[rule->po.imodule].ports[rule->po.iport].enabled;
   rule->po.idx = device.modules[rule->po.imodule].ports[rule->po.iport].idx;

  return (ret);
}


bool MyPlc::rebuild()
{
    idx_t nMO=0,nPI=0,nPO=0,nRL=0;
    idx_t  i,j;

    for (i = 0; i < device.nModules; i++ ) {      // Renumber active modules
     if (  device.modules[i].enabled ) {
        device.modules[i].idx = nMO;
        nMO++;

        for (j = 0; j < device.modules[i].nports; j++ )        // Renumber In/Out ports
        {
          if ( device.modules[i].ports[j].enabled) {         // Only enabled ports
              if ( device.modules[i].ports[j].io) {         // Input
                 device.modules[i].ports[j].idx = nPI;
                 nPI++;
              } else {                                   // Output
                 device.modules[i].ports[j].idx = nPO;
                 nPO++;
              }
           device.modules[i].ports[j].idx = 0;
          }
        }  // All ports
     } else { device.modules[i].idx =0; }
    }

    for (i = 0; i < device.nRules; i++ ) {      // Reassign rules port's idx
       if ( device.rules[i].enabled ) {
            if ( ! rebuildRule(&(device.rules[i])) ) {
               device.rules[i].enabled = false;
               device.rules[i].idx = 0;
            } else {
               device.rules[i].idx = nRL;
               nRL++;
            }
       }
    }

   device.wdatas.nmo = nMO;
   device.wdatas.npi = nPI;
   device.wdatas.npo = nPO;
   device.wdatas.nrl = nRL;
  return (true);
};



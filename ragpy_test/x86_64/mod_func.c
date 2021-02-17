#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _SynE_reg(void);
extern void _ahp_reg(void);
extern void _cabuff_reg(void);
extern void _cal_reg(void);
extern void _can_reg(void);
extern void _kaar_reg(void);
extern void _kdr_reg(void);
extern void _naf_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"mod/SynE.mod\"");
    fprintf(stderr," \"mod/ahp.mod\"");
    fprintf(stderr," \"mod/cabuff.mod\"");
    fprintf(stderr," \"mod/cal.mod\"");
    fprintf(stderr," \"mod/can.mod\"");
    fprintf(stderr," \"mod/kaar.mod\"");
    fprintf(stderr," \"mod/kdr.mod\"");
    fprintf(stderr," \"mod/naf.mod\"");
    fprintf(stderr, "\n");
  }
  _SynE_reg();
  _ahp_reg();
  _cabuff_reg();
  _cal_reg();
  _can_reg();
  _kaar_reg();
  _kdr_reg();
  _naf_reg();
}

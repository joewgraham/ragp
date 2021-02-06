#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _ch_Cacna1b_cp6_reg(void);
extern void _ch_Cacna1c_cp3_reg(void);
extern void _ch_Hcn2_cp10_reg(void);
extern void _ch_Hcn4_cp12_reg(void);
extern void _ch_Kcna1ab1_md80769_reg(void);
extern void _ch_Kcnc1_md74298_reg(void);
extern void _ch_Scn1a_cp35_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," mod/ch_Cacna1b_cp6.mod");
    fprintf(stderr," mod/ch_Cacna1c_cp3.mod");
    fprintf(stderr," mod/ch_Hcn2_cp10.mod");
    fprintf(stderr," mod/ch_Hcn4_cp12.mod");
    fprintf(stderr," mod/ch_Kcna1ab1_md80769.mod");
    fprintf(stderr," mod/ch_Kcnc1_md74298.mod");
    fprintf(stderr," mod/ch_Scn1a_cp35.mod");
    fprintf(stderr, "\n");
  }
  _ch_Cacna1b_cp6_reg();
  _ch_Cacna1c_cp3_reg();
  _ch_Hcn2_cp10_reg();
  _ch_Hcn4_cp12_reg();
  _ch_Kcna1ab1_md80769_reg();
  _ch_Kcnc1_md74298_reg();
  _ch_Scn1a_cp35_reg();
}

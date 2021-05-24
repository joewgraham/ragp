#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _ch_Cacna1a_cp5_reg(void);
extern void _ch_Cacna1a_md229585_reg(void);
extern void _ch_Cacna1b_cp6_reg(void);
extern void _ch_Cacna1c_cp3_reg(void);
extern void _ch_Cacna1d_md121060_reg(void);
extern void _ch_Cacna1g_cp41_reg(void);
extern void _ch_Cacna1g_md229585_reg(void);
extern void _ch_Cacna1i_cp42_reg(void);
extern void _ch_Cacna1i_md19920_reg(void);
extern void _ch_Hcn1_cp9_reg(void);
extern void _ch_Hcn1_md229585_reg(void);
extern void _ch_Hcn2_cp10_reg(void);
extern void _ch_Hcn3_cp11_reg(void);
extern void _ch_Hcn4_cp12_reg(void);
extern void _ch_Kcna1_md232813_reg(void);
extern void _ch_Kcna1ab1_md80769_reg(void);
extern void _ch_Kcnb1_cp23_reg(void);
extern void _ch_Kcnb2_cp24_reg(void);
extern void _ch_Kcnc1_cp27_reg(void);
extern void _ch_Kcnc1_md256632_reg(void);
extern void _ch_Kcnc1_md74298_reg(void);
extern void _ch_Naf_md20756_reg(void);
extern void _ch_Naf_rybak_reg(void);
extern void _ch_Scn1a_cp35_reg(void);
extern void _ch_Scn1a_md256632_reg(void);
extern void _ch_Scn1a_md264834_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," \"new_genemods/ch_Cacna1a_cp5.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1a_md229585.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1b_cp6.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1c_cp3.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1d_md121060.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1g_cp41.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1g_md229585.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1i_cp42.mod\"");
    fprintf(stderr," \"new_genemods/ch_Cacna1i_md19920.mod\"");
    fprintf(stderr," \"new_genemods/ch_Hcn1_cp9.mod\"");
    fprintf(stderr," \"new_genemods/ch_Hcn1_md229585.mod\"");
    fprintf(stderr," \"new_genemods/ch_Hcn2_cp10.mod\"");
    fprintf(stderr," \"new_genemods/ch_Hcn3_cp11.mod\"");
    fprintf(stderr," \"new_genemods/ch_Hcn4_cp12.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcna1_md232813.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcna1ab1_md80769.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcnb1_cp23.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcnb2_cp24.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcnc1_cp27.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcnc1_md256632.mod\"");
    fprintf(stderr," \"new_genemods/ch_Kcnc1_md74298.mod\"");
    fprintf(stderr," \"new_genemods/ch_Naf_md20756.mod\"");
    fprintf(stderr," \"new_genemods/ch_Naf_rybak.mod\"");
    fprintf(stderr," \"new_genemods/ch_Scn1a_cp35.mod\"");
    fprintf(stderr," \"new_genemods/ch_Scn1a_md256632.mod\"");
    fprintf(stderr," \"new_genemods/ch_Scn1a_md264834.mod\"");
    fprintf(stderr, "\n");
  }
  _ch_Cacna1a_cp5_reg();
  _ch_Cacna1a_md229585_reg();
  _ch_Cacna1b_cp6_reg();
  _ch_Cacna1c_cp3_reg();
  _ch_Cacna1d_md121060_reg();
  _ch_Cacna1g_cp41_reg();
  _ch_Cacna1g_md229585_reg();
  _ch_Cacna1i_cp42_reg();
  _ch_Cacna1i_md19920_reg();
  _ch_Hcn1_cp9_reg();
  _ch_Hcn1_md229585_reg();
  _ch_Hcn2_cp10_reg();
  _ch_Hcn3_cp11_reg();
  _ch_Hcn4_cp12_reg();
  _ch_Kcna1_md232813_reg();
  _ch_Kcna1ab1_md80769_reg();
  _ch_Kcnb1_cp23_reg();
  _ch_Kcnb2_cp24_reg();
  _ch_Kcnc1_cp27_reg();
  _ch_Kcnc1_md256632_reg();
  _ch_Kcnc1_md74298_reg();
  _ch_Naf_md20756_reg();
  _ch_Naf_rybak_reg();
  _ch_Scn1a_cp35_reg();
  _ch_Scn1a_md256632_reg();
  _ch_Scn1a_md264834_reg();
}

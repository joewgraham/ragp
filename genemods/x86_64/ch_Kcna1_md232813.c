/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__ch_Kcna1_md232813
#define _nrn_initial _nrn_initial__ch_Kcna1_md232813
#define nrn_cur _nrn_cur__ch_Kcna1_md232813
#define _nrn_current _nrn_current__ch_Kcna1_md232813
#define nrn_jacob _nrn_jacob__ch_Kcna1_md232813
#define nrn_state _nrn_state__ch_Kcna1_md232813
#define _net_receive _net_receive__ch_Kcna1_md232813 
#define _f_trates _f_trates__ch_Kcna1_md232813 
#define rates rates__ch_Kcna1_md232813 
#define states states__ch_Kcna1_md232813 
#define trates trates__ch_Kcna1_md232813 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gkcnabar _p[0]
#define ik _p[1]
#define gkcna _p[2]
#define w2 _p[3]
#define z2 _p[4]
#define ek _p[5]
#define Dw2 _p[6]
#define Dz2 _p[7]
#define _g _p[8]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static void _hoc_states(void);
 static void _hoc_trates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_ch_Kcna1_md232813", _hoc_setdata,
 "rates_ch_Kcna1_md232813", _hoc_rates,
 "states_ch_Kcna1_md232813", _hoc_states,
 "trates_ch_Kcna1_md232813", _hoc_trates,
 0, 0
};
 /* declare global and static user variables */
#define aa2 aa2_ch_Kcna1_md232813
 double aa2 = 35;
#define bb2 bb2_ch_Kcna1_md232813
 double bb2 = 7;
#define cc2 cc2_ch_Kcna1_md232813
 double cc2 = 0.25;
#define dd2 dd2_ch_Kcna1_md232813
 double dd2 = 71;
#define ee2 ee2_ch_Kcna1_md232813
 double ee2 = 150;
#define ff2 ff2_ch_Kcna1_md232813
 double ff2 = 120;
#define gg2 gg2_ch_Kcna1_md232813
 double gg2 = 6;
#define hh2 hh2_ch_Kcna1_md232813
 double hh2 = 80;
#define ii2 ii2_ch_Kcna1_md232813
 double ii2 = 24;
#define jj2 jj2_ch_Kcna1_md232813
 double jj2 = 70;
#define kk2 kk2_ch_Kcna1_md232813
 double kk2 = 59;
#define ll2 ll2_ch_Kcna1_md232813
 double ll2 = 7;
#define mm2 mm2_ch_Kcna1_md232813
 double mm2 = 1.3;
#define nn2 nn2_ch_Kcna1_md232813
 double nn2 = 1000;
#define oo2 oo2_ch_Kcna1_md232813
 double oo2 = 60;
#define pp2 pp2_ch_Kcna1_md232813
 double pp2 = 20;
#define qq2 qq2_ch_Kcna1_md232813
 double qq2 = 60;
#define rr2 rr2_ch_Kcna1_md232813
 double rr2 = 8;
#define ss2 ss2_ch_Kcna1_md232813
 double ss2 = 50;
#define usetable usetable_ch_Kcna1_md232813
 double usetable = 1;
#define wtau2 wtau2_ch_Kcna1_md232813
 double wtau2 = 0;
#define winf2 winf2_ch_Kcna1_md232813
 double winf2 = 0;
#define zss2 zss2_ch_Kcna1_md232813
 double zss2 = 0.9;
#define ztau2 ztau2_ch_Kcna1_md232813
 double ztau2 = 0;
#define zinf2 zinf2_ch_Kcna1_md232813
 double zinf2 = 0;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "aa2_ch_Kcna1_md232813", 0, 1000,
 "bb2_ch_Kcna1_md232813", 0, 1000,
 "cc2_ch_Kcna1_md232813", 0, 1000,
 "dd2_ch_Kcna1_md232813", 0, 1000,
 "ee2_ch_Kcna1_md232813", 0, 1000,
 "ff2_ch_Kcna1_md232813", 0, 1000,
 "gg2_ch_Kcna1_md232813", 0, 1000,
 "gkcnabar_ch_Kcna1_md232813", 0, 1e+09,
 "hh2_ch_Kcna1_md232813", 0, 1000,
 "ii2_ch_Kcna1_md232813", 0, 1000,
 "jj2_ch_Kcna1_md232813", 0, 1000,
 "kk2_ch_Kcna1_md232813", 0, 1000,
 "ll2_ch_Kcna1_md232813", 0, 1000,
 "mm2_ch_Kcna1_md232813", 0, 1000,
 "nn2_ch_Kcna1_md232813", 0, 10000,
 "oo2_ch_Kcna1_md232813", 0, 1000,
 "pp2_ch_Kcna1_md232813", 0, 1000,
 "qq2_ch_Kcna1_md232813", 0, 1000,
 "rr2_ch_Kcna1_md232813", 0, 1000,
 "ss2_ch_Kcna1_md232813", 0, 1000,
 "usetable_ch_Kcna1_md232813", 0, 1,
 "zss2_ch_Kcna1_md232813", 0, 1000,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "wtau2_ch_Kcna1_md232813", "ms",
 "ztau2_ch_Kcna1_md232813", "ms",
 "gkcnabar_ch_Kcna1_md232813", "mho/cm2",
 "ik_ch_Kcna1_md232813", "mA/cm2",
 "gkcna_ch_Kcna1_md232813", "mho/cm2",
 0,0
};
 static double delta_t = 1;
 static double v = 0;
 static double w20 = 0;
 static double z20 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "aa2_ch_Kcna1_md232813", &aa2_ch_Kcna1_md232813,
 "bb2_ch_Kcna1_md232813", &bb2_ch_Kcna1_md232813,
 "cc2_ch_Kcna1_md232813", &cc2_ch_Kcna1_md232813,
 "dd2_ch_Kcna1_md232813", &dd2_ch_Kcna1_md232813,
 "ee2_ch_Kcna1_md232813", &ee2_ch_Kcna1_md232813,
 "ff2_ch_Kcna1_md232813", &ff2_ch_Kcna1_md232813,
 "gg2_ch_Kcna1_md232813", &gg2_ch_Kcna1_md232813,
 "hh2_ch_Kcna1_md232813", &hh2_ch_Kcna1_md232813,
 "ii2_ch_Kcna1_md232813", &ii2_ch_Kcna1_md232813,
 "jj2_ch_Kcna1_md232813", &jj2_ch_Kcna1_md232813,
 "kk2_ch_Kcna1_md232813", &kk2_ch_Kcna1_md232813,
 "ll2_ch_Kcna1_md232813", &ll2_ch_Kcna1_md232813,
 "mm2_ch_Kcna1_md232813", &mm2_ch_Kcna1_md232813,
 "nn2_ch_Kcna1_md232813", &nn2_ch_Kcna1_md232813,
 "oo2_ch_Kcna1_md232813", &oo2_ch_Kcna1_md232813,
 "pp2_ch_Kcna1_md232813", &pp2_ch_Kcna1_md232813,
 "qq2_ch_Kcna1_md232813", &qq2_ch_Kcna1_md232813,
 "rr2_ch_Kcna1_md232813", &rr2_ch_Kcna1_md232813,
 "ss2_ch_Kcna1_md232813", &ss2_ch_Kcna1_md232813,
 "zss2_ch_Kcna1_md232813", &zss2_ch_Kcna1_md232813,
 "winf2_ch_Kcna1_md232813", &winf2_ch_Kcna1_md232813,
 "zinf2_ch_Kcna1_md232813", &zinf2_ch_Kcna1_md232813,
 "wtau2_ch_Kcna1_md232813", &wtau2_ch_Kcna1_md232813,
 "ztau2_ch_Kcna1_md232813", &ztau2_ch_Kcna1_md232813,
 "usetable_ch_Kcna1_md232813", &usetable_ch_Kcna1_md232813,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ch_Kcna1_md232813",
 "gkcnabar_ch_Kcna1_md232813",
 0,
 "ik_ch_Kcna1_md232813",
 "gkcna_ch_Kcna1_md232813",
 0,
 "w2_ch_Kcna1_md232813",
 "z2_ch_Kcna1_md232813",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 9, _prop);
 	/*initialize range parameters*/
 	gkcnabar = 0.01592;
 	_prop->param = _p;
 	_prop->param_size = 9;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ch_Kcna1_md232813_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 9, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ch_Kcna1_md232813 /Users/jessicafeldman/Desktop/ragp/ragp/genemods/ch_Kcna1_md232813.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double _zwexp2 , _zzexp2 ;
 static double _zq10 ;
 static double *_t_winf2;
 static double *_t__zwexp2;
 static double *_t_zinf2;
 static double *_t__zzexp2;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_trates(double);
static int rates(double);
static int states();
static int trates(double);
 static void _n_trates(double);
 
static int  states (  ) {
   trates ( _threadargscomma_ v ) ;
   w2 = w2 + _zwexp2 * ( winf2 - w2 ) ;
   z2 = z2 + _zzexp2 * ( zinf2 - z2 ) ;
   
/*VERBATIM*/
	return 0;
  return 0; }
 
static void _hoc_states(void) {
  double _r;
   _r = 1.;
 states (  );
 hoc_retpushx(_r);
}
 
static int  rates (  double _lv ) {
   winf2 = pow( ( 1.0 / ( 1.0 + exp ( - ( _lv + aa2 ) / bb2 ) ) ) , cc2 ) ;
   zinf2 = zss2 + ( ( 1.0 - zss2 ) / ( 1.0 + exp ( ( _lv + dd2 ) / ee2 ) ) ) ;
   wtau2 = ( ff2 / ( gg2 * exp ( ( _lv + hh2 ) / ii2 ) + jj2 * exp ( - ( _lv + kk2 ) / ll2 ) ) ) + mm2 ;
   ztau2 = ( nn2 / ( exp ( ( _lv + oo2 ) / pp2 ) + exp ( - ( _lv + qq2 ) / rr2 ) ) ) + ss2 ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_trates, _tmin_trates;
 static void _check_trates();
 static void _check_trates() {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_dt;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_dt != dt) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_trates =  - 150.0 ;
   _tmax =  150.0 ;
   _dx = (_tmax - _tmin_trates)/300.; _mfac_trates = 1./_dx;
   for (_i=0, _x=_tmin_trates; _i < 301; _x += _dx, _i++) {
    _f_trates(_x);
    _t_winf2[_i] = winf2;
    _t__zwexp2[_i] = _zwexp2;
    _t_zinf2[_i] = zinf2;
    _t__zzexp2[_i] = _zzexp2;
   }
   _sav_dt = dt;
   _sav_celsius = celsius;
  }
 }

 static int trates(double _lv){ _check_trates();
 _n_trates(_lv);
 return 0;
 }

 static void _n_trates(double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_trates(_lv); return; 
}
 _xi = _mfac_trates * (_lv - _tmin_trates);
 if (isnan(_xi)) {
  winf2 = _xi;
  _zwexp2 = _xi;
  zinf2 = _xi;
  _zzexp2 = _xi;
  return;
 }
 if (_xi <= 0.) {
 winf2 = _t_winf2[0];
 _zwexp2 = _t__zwexp2[0];
 zinf2 = _t_zinf2[0];
 _zzexp2 = _t__zzexp2[0];
 return; }
 if (_xi >= 300.) {
 winf2 = _t_winf2[300];
 _zwexp2 = _t__zwexp2[300];
 zinf2 = _t_zinf2[300];
 _zzexp2 = _t__zzexp2[300];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 winf2 = _t_winf2[_i] + _theta*(_t_winf2[_i+1] - _t_winf2[_i]);
 _zwexp2 = _t__zwexp2[_i] + _theta*(_t__zwexp2[_i+1] - _t__zwexp2[_i]);
 zinf2 = _t_zinf2[_i] + _theta*(_t_zinf2[_i+1] - _t_zinf2[_i]);
 _zzexp2 = _t__zzexp2[_i] + _theta*(_t__zzexp2[_i+1] - _t__zzexp2[_i]);
 }

 
static int  _f_trates (  double _lv ) {
   double _ltinc ;
 _zq10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   rates ( _threadargscomma_ _lv ) ;
   _ltinc = - dt * _zq10 ;
   _zwexp2 = 1.0 - exp ( _ltinc / wtau2 ) ;
   _zzexp2 = 1.0 - exp ( _ltinc / ztau2 ) ;
    return 0; }
 
static void _hoc_trates(void) {
  double _r;
    _r = 1.;
 trates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("ch_Kcna1_md232813", "cannot be used with CVODE"); return 0;}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  w2 = w20;
  z2 = z20;
 {
   trates ( _threadargscomma_ v ) ;
   w2 = winf2 ;
   z2 = zinf2 ;
   }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   gkcna = gkcnabar * ( pow( w2 , 4.0 ) ) * z2 ;
   ik = gkcna * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 { error =  states();
 if(error){fprintf(stderr,"at line 67 in file ch_Kcna1_md232813.mod:\n    \n"); nrn_complain(_p); abort_run(error);}
 } }}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
   _t_winf2 = makevector(301*sizeof(double));
   _t__zwexp2 = makevector(301*sizeof(double));
   _t_zinf2 = makevector(301*sizeof(double));
   _t__zzexp2 = makevector(301*sizeof(double));
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/genemods/ch_Kcna1_md232813.mod";
static const char* nmodl_file_text = 
  ": kcna.mod codes low-threshold K+ channel Kv1.1 encoded in zebrafish kcna1a.\n"
  ": Default parameters of a H-H equation are fitted to our experimental data\n"
  ": by using our channel generator. \n"
  ":\n"
  ": Takaki Watanabe\n"
  ": wtakaki@m.u-tokyo.ac.jp\n"
  "\n"
  "UNITS {\n"
  "        (mA) = (milliamp)\n"
  "        (mV) = (millivolt)\n"
  "        (nA) = (nanoamp)\n"
  "}\n"
  "\n"
  "NEURON {\n"
  "        SUFFIX ch_Kcna1_md232813\n"
  "        USEION k READ ek WRITE ik\n"
  "        RANGE gkcnabar, gkcna, ik\n"
  "        GLOBAL winf2, zinf2, wtau2, ztau2\n"
  "		GLOBAL aa2,bb2,cc2,dd2,ee2,ff2,gg2,hh2,ii2,jj2,kk2,ll2,mm2,nn2,oo2,pp2,qq2,rr2,ss2\n"
  "}\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "PARAMETER {\n"
  "        v (mV)\n"
  "        celsius = 20 (degC)  \n"
  "        dt (ms)\n"
  "        ek = -90 (mV)\n"
  "        gkcnabar = 0.01592 (mho/cm2) <0,1e9>\n"
  "		aa2= 35 <0,1e3>\n"
  "		bb2= 7 <0,1e3>\n"
  "		cc2= 0.25 <0,1e3>\n"
  "		dd2= 71 <0,1e3>\n"
  "		ee2= 150 <0,1e3>\n"
  "		ff2= 120 <0,1e3>\n"
  "		gg2= 6 <0,1e3>\n"
  "		hh2= 80 <0,1e3>\n"
  "		ii2= 24 <0,1e3>\n"
  "		jj2= 70 <0,1e3>\n"
  "		kk2= 59 <0,1e3>\n"
  "		ll2= 7 <0,1e3>\n"
  "		mm2= 1.3 <0,1e3>\n"
  "		nn2= 1000 <0,1e4>\n"
  "		oo2= 60 <0,1e3>\n"
  "		pp2= 20 <0,1e3>\n"
  "		qq2= 60 <0,1e3>\n"
  "		rr2= 8 <0,1e3>\n"
  "		ss2= 50 <0,1e3>\n"
  "        zss2 = 0.9   <0,1e3>   : steady state inactivation of glt\n"
  "}\n"
  "\n"
  "STATE {\n"
  "        w2 z2\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    ik (mA/cm2) \n"
  "    gkcna (mho/cm2)\n"
  "    winf2 zinf2\n"
  "    wtau2 (ms) ztau2 (ms)\n"
  "    }\n"
  "\n"
  "LOCAL wexp2, zexp2\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states\n"
  "    \n"
  "	gkcna = gkcnabar*(w2^4)*z2\n"
  "    ik = gkcna*(v - ek)\n"
  "\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "INITIAL {\n"
  "    trates(v)\n"
  "    w2 = winf2\n"
  "    z2 = zinf2\n"
  "}\n"
  "\n"
  "PROCEDURE states() {  :Computes state variables m, h, and n\n"
  "	trates(v)      :             at the current v and dt.\n"
  "	w2 = w2 + wexp2*(winf2-w2)\n"
  "	z2 = z2 + zexp2*(zinf2-z2)\n"
  "VERBATIM\n"
  "	return 0;\n"
  "ENDVERBATIM\n"
  "}\n"
  "\n"
  "LOCAL q10\n"
  "\n"
  "PROCEDURE rates(v) {  :Computes rate and other constants at current v.\n"
  "                      :Call once from HOC to initialize inf at resting v.\n"
  "  \n"
  "    winf2 = (1 / (1 + exp(-(v + aa2) / bb2)))^cc2\n"
  "    zinf2 = zss2 + ((1-zss2) / (1 + exp((v + dd2) / ee2)))\n"
  "\n"
  "    wtau2 =  (ff2 / (gg2*exp((v+hh2) / ii2) + jj2*exp(-(v+kk2) / ll2))) + mm2\n"
  "    ztau2 =  (nn2 / (exp((v+oo2) / pp2) + exp(-(v+qq2) / rr2))) + ss2\n"
  "}\n"
  "\n"
  "PROCEDURE trates(v) {  :Computes rate and other constants at current v.\n"
  "                      :Call once from HOC to initialize inf at resting v.\n"
  "	LOCAL tinc\n"
  "	TABLE winf2, wexp2, zinf2, zexp2\n"
  "	DEPEND dt, celsius FROM -150 TO 150 WITH 300\n"
  "	\n"
  "    q10 = 3^((celsius - 20)/10) \n"
  "    rates(v)    \n"
  "	tinc = -dt * q10\n"
  "	wexp2 = 1 - exp(tinc/wtau2)\n"
  "	zexp2 = 1 - exp(tinc/ztau2)\n"
  "	}\n"
  "\n"
  "\n"
  "UNITSON\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif

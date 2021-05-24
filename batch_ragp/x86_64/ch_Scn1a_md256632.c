/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
 
#define nrn_init _nrn_init__ch_Scn1a_md256632
#define _nrn_initial _nrn_initial__ch_Scn1a_md256632
#define nrn_cur _nrn_cur__ch_Scn1a_md256632
#define _nrn_current _nrn_current__ch_Scn1a_md256632
#define nrn_jacob _nrn_jacob__ch_Scn1a_md256632
#define nrn_state _nrn_state__ch_Scn1a_md256632
#define _net_receive _net_receive__ch_Scn1a_md256632 
#define _f_settables _f_settables__ch_Scn1a_md256632 
#define settables settables__ch_Scn1a_md256632 
#define states states__ch_Scn1a_md256632 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gnabar _p[0]
#define ina _p[1]
#define gna _p[2]
#define m _p[3]
#define h _p[4]
#define ena _p[5]
#define minf _p[6]
#define hinf _p[7]
#define mtau _p[8]
#define htau _p[9]
#define Dm _p[10]
#define Dh _p[11]
#define v _p[12]
#define _g _p[13]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_settables(void);
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
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_ch_Scn1a_md256632", _hoc_setdata,
 "settables_ch_Scn1a_md256632", _hoc_settables,
 0, 0
};
 
static void _check_settables(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_settables(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define ahtaur ahtaur_ch_Scn1a_md256632
 double ahtaur = 0.17;
#define ahtaul ahtaul_ch_Scn1a_md256632
 double ahtaul = 1.98;
#define amtaur amtaur_ch_Scn1a_md256632
 double amtaur = 0.015;
#define amtaul amtaul_ch_Scn1a_md256632
 double amtaul = 0.006;
#define brkvhtau brkvhtau_ch_Scn1a_md256632
 double brkvhtau = -55;
#define bhtaur bhtaur_ch_Scn1a_md256632
 double bhtaur = 10.82;
#define bhtaul bhtaul_ch_Scn1a_md256632
 double bhtaul = 8.54;
#define brkvmtau brkvmtau_ch_Scn1a_md256632
 double brkvmtau = -50;
#define bmtaur bmtaur_ch_Scn1a_md256632
 double bmtaur = 0.065;
#define bmtaul bmtaul_ch_Scn1a_md256632
 double bmtaul = 0.08;
#define chtaur chtaur_ch_Scn1a_md256632
 double chtaur = -39.1;
#define chtaul chtaul_ch_Scn1a_md256632
 double chtaul = -73.3;
#define cmtaur cmtaur_ch_Scn1a_md256632
 double cmtaur = -10.8;
#define cmtaul cmtaul_ch_Scn1a_md256632
 double cmtaul = -55;
#define dhtaur dhtaur_ch_Scn1a_md256632
 double dhtaur = 4.59;
#define dhtaul dhtaul_ch_Scn1a_md256632
 double dhtaul = 4.7;
#define dmtaur dmtaur_ch_Scn1a_md256632
 double dmtaur = 10;
#define dmtaul dmtaul_ch_Scn1a_md256632
 double dmtaul = 12;
#define khinf khinf_ch_Scn1a_md256632
 double khinf = 12;
#define kminf kminf_ch_Scn1a_md256632
 double kminf = 5.5;
#define usetable usetable_ch_Scn1a_md256632
 double usetable = 1;
#define vhhinf vhhinf_ch_Scn1a_md256632
 double vhhinf = -40;
#define vhminf vhminf_ch_Scn1a_md256632
 double vhminf = -35;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_ch_Scn1a_md256632", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gnabar_ch_Scn1a_md256632", "S/cm2",
 "ina_ch_Scn1a_md256632", "mA/cm2",
 "gna_ch_Scn1a_md256632", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "vhminf_ch_Scn1a_md256632", &vhminf_ch_Scn1a_md256632,
 "kminf_ch_Scn1a_md256632", &kminf_ch_Scn1a_md256632,
 "amtaul_ch_Scn1a_md256632", &amtaul_ch_Scn1a_md256632,
 "bmtaul_ch_Scn1a_md256632", &bmtaul_ch_Scn1a_md256632,
 "cmtaul_ch_Scn1a_md256632", &cmtaul_ch_Scn1a_md256632,
 "dmtaul_ch_Scn1a_md256632", &dmtaul_ch_Scn1a_md256632,
 "brkvmtau_ch_Scn1a_md256632", &brkvmtau_ch_Scn1a_md256632,
 "amtaur_ch_Scn1a_md256632", &amtaur_ch_Scn1a_md256632,
 "bmtaur_ch_Scn1a_md256632", &bmtaur_ch_Scn1a_md256632,
 "cmtaur_ch_Scn1a_md256632", &cmtaur_ch_Scn1a_md256632,
 "dmtaur_ch_Scn1a_md256632", &dmtaur_ch_Scn1a_md256632,
 "vhhinf_ch_Scn1a_md256632", &vhhinf_ch_Scn1a_md256632,
 "khinf_ch_Scn1a_md256632", &khinf_ch_Scn1a_md256632,
 "ahtaul_ch_Scn1a_md256632", &ahtaul_ch_Scn1a_md256632,
 "bhtaul_ch_Scn1a_md256632", &bhtaul_ch_Scn1a_md256632,
 "chtaul_ch_Scn1a_md256632", &chtaul_ch_Scn1a_md256632,
 "dhtaul_ch_Scn1a_md256632", &dhtaul_ch_Scn1a_md256632,
 "brkvhtau_ch_Scn1a_md256632", &brkvhtau_ch_Scn1a_md256632,
 "ahtaur_ch_Scn1a_md256632", &ahtaur_ch_Scn1a_md256632,
 "bhtaur_ch_Scn1a_md256632", &bhtaur_ch_Scn1a_md256632,
 "chtaur_ch_Scn1a_md256632", &chtaur_ch_Scn1a_md256632,
 "dhtaur_ch_Scn1a_md256632", &dhtaur_ch_Scn1a_md256632,
 "usetable_ch_Scn1a_md256632", &usetable_ch_Scn1a_md256632,
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
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ch_Scn1a_md256632",
 "gnabar_ch_Scn1a_md256632",
 0,
 "ina_ch_Scn1a_md256632",
 "gna_ch_Scn1a_md256632",
 0,
 "m_ch_Scn1a_md256632",
 "h_ch_Scn1a_md256632",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	gnabar = 0.008;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _ch_Scn1a_md256632_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 14, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ch_Scn1a_md256632 /Users/jessicafeldman/Desktop/ragp/ragp/batch_ragp/new_genemods/ch_Scn1a_md256632.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_minf;
 static double *_t_mtau;
 static double *_t_hinf;
 static double *_t_htau;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_settables(_threadargsprotocomma_ double);
static int settables(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static void _n_settables(_threadargsprotocomma_ double _lv);
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   settables ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   Dh = ( hinf - h ) / htau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 settables ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / htau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   settables ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtau)))*(- ( ( ( minf ) ) / mtau ) / ( ( ( ( - 1.0 ) ) ) / mtau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / htau)))*(- ( ( ( hinf ) ) / htau ) / ( ( ( ( - 1.0 ) ) ) / htau ) - h) ;
   }
  return 0;
}
 static double _mfac_settables, _tmin_settables;
  static void _check_settables(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  if (!usetable) {return;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_settables =  - 100.0 ;
   _tmax =  100.0 ;
   _dx = (_tmax - _tmin_settables)/200.; _mfac_settables = 1./_dx;
   for (_i=0, _x=_tmin_settables; _i < 201; _x += _dx, _i++) {
    _f_settables(_p, _ppvar, _thread, _nt, _x);
    _t_minf[_i] = minf;
    _t_mtau[_i] = mtau;
    _t_hinf[_i] = hinf;
    _t_htau[_i] = htau;
   }
  }
 }

 static int settables(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv) { 
#if 0
_check_settables(_p, _ppvar, _thread, _nt);
#endif
 _n_settables(_p, _ppvar, _thread, _nt, _lv);
 return 0;
 }

 static void _n_settables(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_settables(_p, _ppvar, _thread, _nt, _lv); return; 
}
 _xi = _mfac_settables * (_lv - _tmin_settables);
 if (isnan(_xi)) {
  minf = _xi;
  mtau = _xi;
  hinf = _xi;
  htau = _xi;
  return;
 }
 if (_xi <= 0.) {
 minf = _t_minf[0];
 mtau = _t_mtau[0];
 hinf = _t_hinf[0];
 htau = _t_htau[0];
 return; }
 if (_xi >= 200.) {
 minf = _t_minf[200];
 mtau = _t_mtau[200];
 hinf = _t_hinf[200];
 htau = _t_htau[200];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 minf = _t_minf[_i] + _theta*(_t_minf[_i+1] - _t_minf[_i]);
 mtau = _t_mtau[_i] + _theta*(_t_mtau[_i+1] - _t_mtau[_i]);
 hinf = _t_hinf[_i] + _theta*(_t_hinf[_i+1] - _t_hinf[_i]);
 htau = _t_htau[_i] + _theta*(_t_htau[_i+1] - _t_htau[_i]);
 }

 
static int  _f_settables ( _threadargsprotocomma_ double _lv ) {
   minf = 1.0 / ( 1.0 + exp ( - ( _lv - vhminf ) / kminf ) ) ;
   if ( _lv < brkvmtau ) {
     mtau = amtaul + bmtaul * ( 1.0 / ( 1.0 + exp ( - ( _lv - cmtaul ) / dmtaul ) ) ) ;
     }
   else {
     mtau = amtaur + bmtaur * ( 1.0 / ( 1.0 + exp ( ( _lv - cmtaur ) / dmtaur ) ) ) ;
     }
   hinf = 1.0 / ( 1.0 + exp ( ( _lv - vhhinf ) / khinf ) ) ;
   if ( _lv < brkvhtau ) {
     htau = ahtaul + bhtaul * ( 1.0 / ( 1.0 + exp ( - ( _lv - chtaul ) / dhtaul ) ) ) ;
     }
   else {
     htau = ahtaur + bhtaur * ( 1.0 / ( 1.0 + exp ( ( _lv - chtaur ) / dhtaur ) ) ) ;
     }
    return 0; }
 
static void _hoc_settables(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_settables(_p, _ppvar, _thread, _nt);
#endif
 _r = 1.;
 settables ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
 {
   settables ( _threadargscomma_ v ) ;
   m = minf ;
   h = hinf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];

#if 0
 _check_settables(_p, _ppvar, _thread, _nt);
#endif
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gna = gnabar * pow( m , 3.0 ) * h ;
   ina = gna * ( v - ena ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ena = _ion_ena;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(m) - _p;  _dlist1[0] = &(Dm) - _p;
 _slist1[1] = &(h) - _p;  _dlist1[1] = &(Dh) - _p;
   _t_minf = makevector(201*sizeof(double));
   _t_mtau = makevector(201*sizeof(double));
   _t_hinf = makevector(201*sizeof(double));
   _t_htau = makevector(201*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/batch_ragp/new_genemods/ch_Scn1a_md256632.mod";
static const char* nmodl_file_text = 
  ": Nav1.1 \n"
  "\n"
  "UNITS {\n"
  "    (mV) = (millivolt)\n"
  "    (mA) = (milliamp)\n"
  "    (S) = (siemens)\n"
  "}\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX ch_Scn1a_md256632\n"
  "    USEION na READ ena WRITE ina\n"
  "    RANGE gnabar, gna, ina\n"
  "    GLOBAL vhminf, kminf, amtaul, bmtaul, cmtaul, dmtaul, amtaur, bmtaur, cmtaur, dmtaur,brkvmtau\n"
  "    GLOBAL vhhinf, khinf, ahtaul, bhtaul, chtaul, dhtaul, ahtaur, bhtaur, chtaur, dhtaur, brkvhtau\n"
  "}\n"
  "\n"
  "PARAMETER{ \n"
  "    gnabar = 0.008 (S/cm2)\n"
  "    ena = 55 (mV)\n"
  "    vhminf = -35\n"
  "    kminf = 5.5\n"
  "    amtaul = 0.006\n"
  "    bmtaul = 0.08\n"
  "    cmtaul = -55\n"
  "    dmtaul = 12\n"
  "    brkvmtau = -50\n"
  "    amtaur = 0.015\n"
  "    bmtaur = 0.065\n"
  "    cmtaur = -10.8\n"
  "    dmtaur = 10\n"
  "    vhhinf = -40\n"
  "    khinf = 12\n"
  "    ahtaul = 1.98\n"
  "    bhtaul = 8.54\n"
  "    chtaul = -73.3\n"
  "    dhtaul = 4.7\n"
  "    brkvhtau = -55\n"
  "    ahtaur = 0.17\n"
  "    bhtaur = 10.82\n"
  "    chtaur = -39.1\n"
  "    dhtaur = 4.59\n"
  "}\n"
  "\n"
  "ASSIGNED{\n"
  "    v (mV)\n"
  "    ina (mA/cm2)\n"
  "    gna (S/cm2)\n"
  "    minf\n"
  "    hinf\n"
  "    mtau (ms) \n"
  "    htau (ms)    \n"
  "}\n"
  "\n"
  "STATE{\n"
  "    m h\n"
  "}\n"
  "\n"
  "BREAKPOINT{\n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    gna = gnabar * m^3 * h\n"
  "    ina = gna * (v - ena)\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "INITIAL{\n"
  "    settables(v)\n"
  "    m = minf\n"
  "    h = hinf\n"
  "}\n"
  "\n"
  "DERIVATIVE states{\n"
  "    settables(v)\n"
  "    m' = (minf-m)/mtau\n"
  "    h' = (hinf-h)/htau\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE settables(v (mV)){\n"
  "    TABLE minf, mtau, hinf, htau\n"
  "    FROM -100 TO 100 WITH 200\n"
  "\n"
  "    minf = 1/(1+exp(-(v-vhminf)/kminf))\n"
  "\n"
  "if (v < brkvmtau){\n"
  "         mtau = amtaul+bmtaul*(1/(1+exp(-(v-cmtaul)/dmtaul)))\n"
  "    }else{\n"
  "         mtau = amtaur+bmtaur*(1/(1+exp((v-cmtaur)/dmtaur)))\n"
  "    }\n"
  "\n"
  "    hinf = 1/(1+exp((v-vhhinf)/khinf))\n"
  "\n"
  "if (v < brkvhtau){\n"
  "         htau = ahtaul+bhtaul*(1/(1+exp(-(v-chtaul)/dhtaul)))\n"
  "    }else{\n"
  "         htau = ahtaur+bhtaur*(1/(1+exp((v-chtaur)/dhtaur)))\n"
  "    }\n"
  "\n"
  "}\n"
  "\n"
  "UNITSON\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif

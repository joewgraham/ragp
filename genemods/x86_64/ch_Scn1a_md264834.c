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
 
#define nrn_init _nrn_init__ch_Scn1a_md264834
#define _nrn_initial _nrn_initial__ch_Scn1a_md264834
#define nrn_cur _nrn_cur__ch_Scn1a_md264834
#define _nrn_current _nrn_current__ch_Scn1a_md264834
#define nrn_jacob _nrn_jacob__ch_Scn1a_md264834
#define nrn_state _nrn_state__ch_Scn1a_md264834
#define _net_receive _net_receive__ch_Scn1a_md264834 
#define rates rates__ch_Scn1a_md264834 
#define states states__ch_Scn1a_md264834 
 
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
#define gNav11bar _p[0]
#define mh _p[1]
#define ms _p[2]
#define hh _p[3]
#define hs _p[4]
#define ina _p[5]
#define gNav11 _p[6]
#define m _p[7]
#define h _p[8]
#define ttxo _p[9]
#define ttxi _p[10]
#define ena _p[11]
#define mInf _p[12]
#define mTau _p[13]
#define hInf _p[14]
#define hTau _p[15]
#define Dm _p[16]
#define Dh _p[17]
#define v _p[18]
#define _g _p[19]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
#define _ion_ttxo	*_ppvar[3]._pval
#define _ion_ttxi	*_ppvar[4]._pval
 
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
 static void _hoc_rates(void);
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
 "setdata_ch_Scn1a_md264834", _hoc_setdata,
 "rates_ch_Scn1a_md264834", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gNav11bar_ch_Scn1a_md264834", "S/cm2",
 "ina_ch_Scn1a_md264834", "mA/cm2",
 "gNav11_ch_Scn1a_md264834", "S/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ch_Scn1a_md264834",
 "gNav11bar_ch_Scn1a_md264834",
 "mh_ch_Scn1a_md264834",
 "ms_ch_Scn1a_md264834",
 "hh_ch_Scn1a_md264834",
 "hs_ch_Scn1a_md264834",
 0,
 "ina_ch_Scn1a_md264834",
 "gNav11_ch_Scn1a_md264834",
 0,
 "m_ch_Scn1a_md264834",
 "h_ch_Scn1a_md264834",
 0,
 0};
 static Symbol* _na_sym;
 static Symbol* _ttx_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 20, _prop);
 	/*initialize range parameters*/
 	gNav11bar = 1e-05;
 	mh = -18.46;
 	ms = 7.91;
 	hh = -48.8;
 	hs = 6.25;
 	_prop->param = _p;
 	_prop->param_size = 20;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 prop_ion = need_memb(_ttx_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[3]._pval = &prop_ion->param[2]; /* ttxo */
 	_ppvar[4]._pval = &prop_ion->param[1]; /* ttxi */
 
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

 void _ch_Scn1a_md264834_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	ion_reg("ttx", 1.0);
 	_na_sym = hoc_lookup("na_ion");
 	_ttx_sym = hoc_lookup("ttx_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 20, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ttx_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "ttx_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ch_Scn1a_md264834 /Users/jessicafeldman/Desktop/ragp/ragp/genemods/ch_Scn1a_md264834.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   if ( ttxi  == 0.015625  && ttxo > 1e-12 ) {
     mInf = 0.0 ;
     mTau = 1e-12 ;
     hInf = 1.0 ;
     hTau = 1e-12 ;
     }
   else {
     rates ( _threadargs_ ) ;
     }
   Dm = ( mInf - m ) / mTau ;
   Dh = ( hInf - h ) / hTau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 if ( ttxi  == 0.015625  && ttxo > 1e-12 ) {
   mInf = 0.0 ;
   mTau = 1e-12 ;
   hInf = 1.0 ;
   hTau = 1e-12 ;
   }
 else {
   rates ( _threadargs_ ) ;
   }
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mTau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / hTau )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   if ( ttxi  == 0.015625  && ttxo > 1e-12 ) {
     mInf = 0.0 ;
     mTau = 1e-12 ;
     hInf = 1.0 ;
     hTau = 1e-12 ;
     }
   else {
     rates ( _threadargs_ ) ;
     }
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mTau)))*(- ( ( ( mInf ) ) / mTau ) / ( ( ( ( - 1.0 ) ) ) / mTau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / hTau)))*(- ( ( ( hInf ) ) / hTau ) / ( ( ( ( - 1.0 ) ) ) / hTau ) - h) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   double _lqt ;
 _lqt = pow( 2.3 , ( ( 34.0 - 24.0 ) / 10.0 ) ) ;
    if ( v  == mh ) {
     v = v + 0.0001 ;
     }
   mTau = ( 0.0876 + 0.35 * exp ( ( - pow( ( - 25.04 - v ) , 2.0 ) ) / 340.13 ) ) / _lqt ;
   mInf = 1.0 / ( 1.0 + exp ( ( mh - v ) / ms ) ) ;
   if ( v  == hh ) {
     v = v + 0.0001 ;
     }
   hTau = ( 0.438 + 12.22 * exp ( ( - pow( ( - 55.53 - v ) , 2.0 ) ) / 547.24 ) ) / _lqt ;
   hInf = 1.0 / ( 1.0 + exp ( ( v - hh ) / hs ) ) ;
     return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
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
  ttxo = _ion_ttxo;
  ttxi = _ion_ttxi;
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
  ttxo = _ion_ttxo;
  ttxi = _ion_ttxi;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
   nrn_update_ion_pointer(_ttx_sym, _ppvar, 3, 2);
   nrn_update_ion_pointer(_ttx_sym, _ppvar, 4, 1);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
 {
   if ( ttxi  == 0.015625  && ttxo > 1e-12 ) {
     mInf = 0.0 ;
     mTau = 1e-12 ;
     hInf = 1.0 ;
     hTau = 1e-12 ;
     }
   else {
     rates ( _threadargs_ ) ;
     }
   m = mInf ;
   h = hInf ;
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
  ttxo = _ion_ttxo;
  ttxi = _ion_ttxi;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gNav11 = gNav11bar * m * m * m * h ;
   ina = gNav11 * ( v - ena ) ;
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
  ttxo = _ion_ttxo;
  ttxi = _ion_ttxi;
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
  ttxo = _ion_ttxo;
  ttxi = _ion_ttxi;
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
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/genemods/ch_Scn1a_md264834.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "\n"
  "\"NaV1.1\" channel.\n"
  "BBP 'fast' Na channel, but activation/inactivation vHalf and slope adjusted to fit experimental data.\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  ":Reference :Colbert and Pan 2002\n"
  "\n"
  ": Adapted by Werner Van Geit @ BBP, 2015 (with help from M.Hines):\n"
  ": channel detects TTX concentration set by TTXDynamicsSwitch.mod\n"
  "\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX ch_Scn1a_md264834\n"
  "	USEION na READ ena WRITE ina\n"
  "	USEION ttx READ ttxo, ttxi VALENCE 1\n"
  "	RANGE gNav11bar, gNav11, ina,mh,ms,hh,hs\n"
  "}\n"
  "\n"
  "UNITS	{\n"
  "	(S) = (siemens)\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "}\n"
  "\n"
  "PARAMETER	{\n"
  "	gNav11bar = 0.00001 (S/cm2)\n"
  "	mh=-18.46 : activation vh\n"
  "	ms=7.91   : activation slope\n"
  "	hh=-48.8 : inactivation vh\n"
  "	hs=6.25   : inactivation slope\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ttxo (mM)\n"
  "	ttxi (mM)\n"
  "	v	(mV)\n"
  "	ena	(mV)\n"
  "	ina	(mA/cm2)\n"
  "	gNav11	(S/cm2)\n"
  "	mInf\n"
  "	mTau\n"
  "	hInf\n"
  "	hTau\n"
  "}\n"
  "\n"
  "STATE	{\n"
  "	m\n"
  "	h\n"
  "}\n"
  "\n"
  "BREAKPOINT	{\n"
  "	SOLVE states METHOD cnexp\n"
  "	gNav11 = gNav11bar*m*m*m*h\n"
  "	ina = gNav11*(v-ena)\n"
  "}\n"
  "\n"
  "DERIVATIVE states	{\n"
  "	if (ttxi == 0.015625 && ttxo > 1e-12) {\n"
  "		mInf = 0.0\n"
  "		mTau = 1e-12\n"
  "		hInf = 1.0\n"
  "		hTau = 1e-12\n"
  "	} else {\n"
  "		rates()\n"
  "	}\n"
  "	m' = (mInf-m)/mTau\n"
  "	h' = (hInf-h)/hTau\n"
  "}\n"
  "\n"
  "INITIAL{\n"
  "	if (ttxi == 0.015625 && ttxo > 1e-12) {\n"
  "		mInf = 0.0\n"
  "		mTau = 1e-12\n"
  "		hInf = 1.0\n"
  "		hTau = 1e-12\n"
  "	} else {\n"
  "		rates()\n"
  "	}\n"
  "	m = mInf\n"
  "	h = hInf\n"
  "}\n"
  "\n"
  "PROCEDURE rates(){\n"
  "  LOCAL qt\n"
  "  qt = 2.3^((34-24)/10) : recordings at 24C\n"
  "\n"
  "  UNITSOFF\n"
  "    if(v == mh){\n"
  "    	v = v+0.0001\n"
  "    }\n"
  "		mTau = (0.0876 + 0.35 * exp((-(-25.04 - v)^2)/ 340.13))/qt\n"
  "		mInf = 1.0/(1.0+exp((mh-v)/ms))\n"
  "\n"
  "    if(v == hh){\n"
  "      v = v + 0.0001\n"
  "    }\n"
  "		hTau = (0.438 + 12.22 * exp((-(-55.53 - v)^2)/ 547.24))/qt\n"
  "		hInf = 1.0/(1.0+exp((v-hh)/hs))\n"
  "	UNITSON\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif

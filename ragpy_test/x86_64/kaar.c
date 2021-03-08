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
 
#define nrn_init _nrn_init__KAAR
#define _nrn_initial _nrn_initial__KAAR
#define nrn_cur _nrn_cur__KAAR
#define _nrn_current _nrn_current__KAAR
#define nrn_jacob _nrn_jacob__KAAR
#define nrn_state _nrn_state__KAAR
#define _net_receive _net_receive__KAAR 
#define rate rate__KAAR 
#define states states__KAAR 
 
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
#define gAbar _p[0]
#define moA1 _p[1]
#define moA2 _p[2]
#define hoA1 _p[3]
#define hoA2 _p[4]
#define gARbar _p[5]
#define ik _p[6]
#define ia _p[7]
#define iar _p[8]
#define gA _p[9]
#define miA1 _p[10]
#define miA2 _p[11]
#define hiA1 _p[12]
#define hiA2 _p[13]
#define tmA1 _p[14]
#define tmA2 _p[15]
#define thA1 _p[16]
#define thA2 _p[17]
#define mA1 _p[18]
#define hA1 _p[19]
#define mA2 _p[20]
#define hA2 _p[21]
#define DmA1 _p[22]
#define DhA1 _p[23]
#define DmA2 _p[24]
#define DhA2 _p[25]
#define ek _p[26]
#define v _p[27]
#define _g _p[28]
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
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_rate(void);
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
 "setdata_KAAR", _hoc_setdata,
 "rate_KAAR", _hoc_rate,
 0, 0
};
 /* declare global and static user variables */
#define T T_KAAR
 double T = 308;
#define z z_KAAR
 double z = 2;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "gAbar_KAAR", 0, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gAbar_KAAR", "S/cm2",
 "gARbar_KAAR", "S/cm2",
 "ik_KAAR", "mA/cm2",
 "ia_KAAR", "mA/cm2",
 "iar_KAAR", "mA/cm2",
 "gA_KAAR", "S/cm2",
 "tmA1_KAAR", "ms",
 "tmA2_KAAR", "ms",
 "thA1_KAAR", "ms",
 "thA2_KAAR", "ms",
 0,0
};
 static double delta_t = 0.01;
 static double hA20 = 0;
 static double hA10 = 0;
 static double mA20 = 0;
 static double mA10 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "z_KAAR", &z_KAAR,
 "T_KAAR", &T_KAAR,
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
"KAAR",
 "gAbar_KAAR",
 "moA1_KAAR",
 "moA2_KAAR",
 "hoA1_KAAR",
 "hoA2_KAAR",
 "gARbar_KAAR",
 0,
 "ik_KAAR",
 "ia_KAAR",
 "iar_KAAR",
 "gA_KAAR",
 "miA1_KAAR",
 "miA2_KAAR",
 "hiA1_KAAR",
 "hiA2_KAAR",
 "tmA1_KAAR",
 "tmA2_KAAR",
 "thA1_KAAR",
 "thA2_KAAR",
 0,
 "mA1_KAAR",
 "hA1_KAAR",
 "mA2_KAAR",
 "hA2_KAAR",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 29, _prop);
 	/*initialize range parameters*/
 	gAbar = 0.00530516;
 	moA1 = 0.451427;
 	moA2 = 0.217068;
 	hoA1 = 0.0615788;
 	hoA2 = 0.0615788;
 	gARbar = 0.00212207;
 	_prop->param = _p;
 	_prop->param_size = 29;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _kaar_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 5);
  _extcall_thread = (Datum*)ecalloc(4, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 29, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 KAAR /Users/jessicafeldman/Desktop/ragp/ragp/ragpy_test/mod/kaar.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 96480;
 static double R = 8.314;
static int _reset;
static char *modelname = "KA channel from PN MATLAB/PYTHON model and KAR (Anomalous Rectifier) channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(_threadargsprotocomma_ double);
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
extern void* nrn_cons_newtonspace(int);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist2[4];
  static int _slist1[4], _dlist1[4];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   DmA1 = 1000.0 * ( miA1 - mA1 ) / tmA1 ;
   DhA1 = 1000.0 * ( hiA1 - hA1 ) / thA1 ;
   DmA2 = 1000.0 * ( miA2 - mA2 ) / tmA2 ;
   DhA2 = 1000.0 * ( hiA2 - hA2 ) / thA2 ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 DmA1 = DmA1  / (1. - dt*( ( ( 1000.0 )*( ( ( - 1.0 ) ) ) ) / tmA1 )) ;
 DhA1 = DhA1  / (1. - dt*( ( ( 1000.0 )*( ( ( - 1.0 ) ) ) ) / thA1 )) ;
 DmA2 = DmA2  / (1. - dt*( ( ( 1000.0 )*( ( ( - 1.0 ) ) ) ) / tmA2 )) ;
 DhA2 = DhA2  / (1. - dt*( ( ( 1000.0 )*( ( ( - 1.0 ) ) ) ) / thA2 )) ;
  return 0;
}
 /*END CVODE*/
 
static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 4;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 4; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 4,_slist2, _p, states, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   rate ( _threadargscomma_ v ) ;
   DmA1 = 1000.0 * ( miA1 - mA1 ) / tmA1 ;
   DhA1 = 1000.0 * ( hiA1 - hA1 ) / thA1 ;
   DmA2 = 1000.0 * ( miA2 - mA2 ) / tmA2 ;
   DhA2 = 1000.0 * ( hiA2 - hA2 ) / thA2 ;
   {int _id; for(_id=0; _id < 4; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
static int  rate ( _threadargsprotocomma_ double _lv ) {
   miA1 = 1.0 / ( 1.0 + ( exp ( - ( _lv + 60.0 ) / 8.5 ) ) ) ;
   tmA1 = 1.0 / ( ( exp ( ( _lv + 35.82 ) / 19.69 ) ) + ( exp ( - ( _lv + 79.69 ) / 12.7 ) ) + 0.37 ) ;
   hiA1 = 1.0 / ( 1.0 + ( exp ( ( _lv + 78.0 ) / 6.0 ) ) ) ;
   if ( _lv >= - 63.0 ) {
     thA1 = 19.0 ;
     }
   else {
     thA1 = 1.0 / ( ( exp ( ( _lv + 46.05 ) / 5.0 ) ) + ( exp ( - ( _lv + 238.4 ) / 37.45 ) ) + 0.37 ) ;
     }
   miA2 = 1.0 / ( 1.0 + ( exp ( - ( _lv + 36.0 ) / 20.0 ) ) ) ;
   tmA2 = 1.0 / ( ( exp ( ( _lv + 35.82 ) / 19.69 ) ) + ( exp ( - ( _lv + 79.69 ) / 12.7 ) ) + 0.37 ) ;
   hiA2 = 1.0 / ( 1.0 + ( exp ( ( _lv + 78.0 ) / 6.0 ) ) ) ;
   if ( _lv >= - 73.0 ) {
     thA2 = 60.0 ;
     }
   else {
     thA2 = 1.0 / ( ( exp ( ( _lv + 46.05 ) / 5.0 ) ) + ( exp ( - ( _lv + 238.4 ) / 37.45 ) ) + 0.37 ) ;
     }
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 4;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 4; ++_i) {
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
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(8, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(4);
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  hA2 = hA20;
  hA1 = hA10;
  mA2 = mA20;
  mA1 = mA10;
 {
   rate ( _threadargscomma_ v ) ;
   mA1 = moA1 ;
   mA2 = moA2 ;
   hA1 = hoA1 ;
   hA2 = hoA2 ;
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
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gA = gAbar * ( ( 0.6 * hA1 * ( pow( mA1 , 4.0 ) ) ) + ( 0.4 * hA2 * ( pow( mA2 , 4.0 ) ) ) ) ;
   ia = gA * ( v - ( - 94.0 ) ) ;
   iar = ( gARbar * ( ( v - ( - 94.0 ) + 5.66 ) / ( 1.0 + ( exp ( ( ( v - ( - 94.0 ) - 15.3 ) * z * FARADAY ) / ( 1000.0 * R * T ) ) ) ) ) ) ;
   ik = 1000.0 * ( ia + iar ) ;
   }
 _current += ik;

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
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
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
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
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
  ek = _ion_ek;
 {  _deriv1_advance = 1;
 derivimplicit_thread(4, _slist1, _dlist1, _p, states, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 4; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(mA1) - _p;  _dlist1[0] = &(DmA1) - _p;
 _slist1[1] = &(hA1) - _p;  _dlist1[1] = &(DhA1) - _p;
 _slist1[2] = &(mA2) - _p;  _dlist1[2] = &(DmA2) - _p;
 _slist1[3] = &(hA2) - _p;  _dlist1[3] = &(DhA2) - _p;
 _slist2[0] = &(hA2) - _p;
 _slist2[1] = &(hA1) - _p;
 _slist2[2] = &(mA2) - _p;
 _slist2[3] = &(mA1) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/ragpy_test/mod/kaar.mod";
static const char* nmodl_file_text = 
  "TITLE KA channel from PN MATLAB/PYTHON model and KAR (Anomalous Rectifier) channel\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX KAAR\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE gAbar, gA, ik, gARbar, iar, ia\n"
  "	RANGE miA1, tmA1, hiA1, thA1, miA2, tmA2, hiA2, thA2, moA1, moA2, hoA1, hoA2\n"
  "	GLOBAL z,T\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)	\n"
  "}\n"
  "\n"
  "CONSTANT {\n"
  "	FARADAY = 96480		(coulomb/mole)		: moles do not appear in units\n"
  "	R = 8.314 (k-mole*joule/degC)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	gAbar = 0.005305165 (S/cm2) <0,1e9>\n"
  "	moA1 = 4.514268765351059e-01\n"
  "	moA2 = 2.170679363371657e-01\n"
  "	hoA1 = 6.157878435363050e-02\n"
  "	hoA2 = 6.157878220370643e-02\n"
  "	gARbar = 0.002122066 (S/cm2)\n"
  "	z = 2\n"
  "	T = 308\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	 mA1 hA1 \n"
  "	 mA2 hA2\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	v (mV)\n"
  "	ik (mA/cm2)\n"
  "	ia (mA/cm2)\n"
  "	iar (mA/cm2)\n"
  "	gA (S/cm2)\n"
  "	miA1\n"
  "	miA2\n"
  "	hiA1\n"
  "	hiA2 \n"
  "	tmA1 (ms)\n"
  "	tmA2 (ms)  \n"
  "	thA1 (ms)\n"
  "	thA2 (ms)\n"
  "	ek (mV)      \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	rate(v)\n"
  "	mA1 = moA1\n"
  "	mA2 = moA2\n"
  "	hA1 = hoA1\n"
  "	hA2 = hoA2\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD derivimplicit\n"
  "	gA=gAbar*((0.6*hA1*(mA1^4))+(0.4*hA2*(mA2^4)))\n"
  "	ia = gA*(v-(-94)) 		: based on M/P code of PN Neuron\n"
  "	iar = (gARbar*((v-(-94)+5.66)/(1+(exp(((v-(-94)-15.3)*z*FARADAY)/(1000*R*T))))))		: based on M/P code of PN Neuron\n"
  "	ik = 1000*(ia+iar)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {	\n"
  "	rate(v)\n"
  "	mA1' = 1000*(miA1 - mA1)/tmA1\n"
  "	hA1' = 1000*(hiA1 - hA1)/thA1\n"
  "	mA2' = 1000*(miA2 - mA2)/tmA2\n"
  "	hA2' = 1000*(hiA2 - hA2)/thA2\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE rate(v(mV)) {\n"
  "	miA1 = 1/(1+(exp(-(v+60)/8.5)))\n"
  "	tmA1 = 1/((exp((v+35.82)/19.69))+(exp(-(v+79.69)/12.7))+0.37)\n"
  "	hiA1 = 1/(1+(exp((v+78)/6)))\n"
  "	if (v>=-63) {\n"
  "		thA1 = 19\n"
  "	} else {\n"
  "		thA1 = 1/((exp((v+46.05)/5))+(exp(-(v+238.4)/37.45))+0.37)\n"
  "	}\n"
  "	miA2 = 1/(1+(exp(-(v+36)/20)))\n"
  "	tmA2 = 1/((exp((v+35.82)/19.69))+(exp(-(v+79.69)/12.7))+0.37)\n"
  "	hiA2 = 1/(1+(exp((v+78)/6)))\n"
  "	if (v>=-73) {\n"
  "		thA2 = 60\n"
  "	} else {\n"
  "		thA2 = 1/((exp((v+46.05)/5))+(exp(-(v+238.4)/37.45))+0.37)\n"
  "	}\n"
  "\n"
  "}\n"
  "UNITSON\n"
  ;
#endif

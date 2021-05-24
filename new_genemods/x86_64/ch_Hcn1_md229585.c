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
 
#define nrn_init _nrn_init__ch_Hcn1_md229585
#define _nrn_initial _nrn_initial__ch_Hcn1_md229585
#define nrn_cur _nrn_cur__ch_Hcn1_md229585
#define _nrn_current _nrn_current__ch_Hcn1_md229585
#define nrn_jacob _nrn_jacob__ch_Hcn1_md229585
#define nrn_state _nrn_state__ch_Hcn1_md229585
#define _net_receive _net_receive__ch_Hcn1_md229585 
#define rate rate__ch_Hcn1_md229585 
#define states states__ch_Hcn1_md229585 
 
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
#define gbar _p[0]
#define ratetau _p[1]
#define ih _p[2]
#define hinf _p[3]
#define tauh _p[4]
#define h _p[5]
#define Dh _p[6]
#define eh _p[7]
#define v_inf_half _p[8]
#define v_tau_half1 _p[9]
#define v_tau_half2 _p[10]
#define qt _p[11]
#define v _p[12]
#define _g _p[13]
#define _ion_eh	*_ppvar[0]._pval
#define _ion_ih	*_ppvar[1]._pval
#define _ion_dihdv	*_ppvar[2]._pval
 
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
 extern double celsius;
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
 "setdata_ch_Hcn1_md229585", _hoc_setdata,
 "rate_ch_Hcn1_md229585", _hoc_rate,
 0, 0
};
 /* declare global and static user variables */
#define ljp ljp_ch_Hcn1_md229585
 double ljp = 9.3;
#define rec_temp rec_temp_ch_Hcn1_md229585
 double rec_temp = 23;
#define v_tau_k2 v_tau_k2_ch_Hcn1_md229585
 double v_tau_k2 = 7.14;
#define v_tau_k1 v_tau_k1_ch_Hcn1_md229585
 double v_tau_k1 = -22;
#define v_tau_half2_noljp v_tau_half2_noljp_ch_Hcn1_md229585
 double v_tau_half2_noljp = -68;
#define v_tau_half1_noljp v_tau_half1_noljp_ch_Hcn1_md229585
 double v_tau_half1_noljp = -68;
#define v_tau_const v_tau_const_ch_Hcn1_md229585
 double v_tau_const = 0.0018;
#define v_inf_k v_inf_k_ch_Hcn1_md229585
 double v_inf_k = 9.67;
#define v_inf_half_noljp v_inf_half_noljp_ch_Hcn1_md229585
 double v_inf_half_noljp = -90.3;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "rec_temp_ch_Hcn1_md229585", "deg",
 "ljp_ch_Hcn1_md229585", "mV",
 "v_inf_half_noljp_ch_Hcn1_md229585", "mV",
 "v_inf_k_ch_Hcn1_md229585", "mV",
 "v_tau_const_ch_Hcn1_md229585", "1",
 "v_tau_half1_noljp_ch_Hcn1_md229585", "mV",
 "v_tau_half2_noljp_ch_Hcn1_md229585", "mV",
 "v_tau_k1_ch_Hcn1_md229585", "mv",
 "v_tau_k2_ch_Hcn1_md229585", "mv",
 "gbar_ch_Hcn1_md229585", "mho/cm2",
 "ratetau_ch_Hcn1_md229585", "ms",
 "ih_ch_Hcn1_md229585", "mA/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "rec_temp_ch_Hcn1_md229585", &rec_temp_ch_Hcn1_md229585,
 "ljp_ch_Hcn1_md229585", &ljp_ch_Hcn1_md229585,
 "v_inf_half_noljp_ch_Hcn1_md229585", &v_inf_half_noljp_ch_Hcn1_md229585,
 "v_inf_k_ch_Hcn1_md229585", &v_inf_k_ch_Hcn1_md229585,
 "v_tau_const_ch_Hcn1_md229585", &v_tau_const_ch_Hcn1_md229585,
 "v_tau_half1_noljp_ch_Hcn1_md229585", &v_tau_half1_noljp_ch_Hcn1_md229585,
 "v_tau_half2_noljp_ch_Hcn1_md229585", &v_tau_half2_noljp_ch_Hcn1_md229585,
 "v_tau_k1_ch_Hcn1_md229585", &v_tau_k1_ch_Hcn1_md229585,
 "v_tau_k2_ch_Hcn1_md229585", &v_tau_k2_ch_Hcn1_md229585,
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
"ch_Hcn1_md229585",
 "gbar_ch_Hcn1_md229585",
 "ratetau_ch_Hcn1_md229585",
 0,
 "ih_ch_Hcn1_md229585",
 "hinf_ch_Hcn1_md229585",
 "tauh_ch_Hcn1_md229585",
 0,
 "h_ch_Hcn1_md229585",
 0,
 0};
 static Symbol* _h_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	gbar = 0.0001;
 	ratetau = 1;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_h_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* eh */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ih */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dihdv */
 
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

 void _ch_Hcn1_md229585_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("h", 1.0);
 	_h_sym = hoc_lookup("h_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 14, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "h_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "h_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "h_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ch_Hcn1_md229585 /Users/jessicafeldman/Desktop/ragp/ragp/new_genemods/ch_Hcn1_md229585.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double q10 = 3;
static int _reset;
static char *modelname = "I-h HCN1 channel from Kamilla Angelo, Michael London,Soren R. Christensen, and Michael Hausser 2007 J. of Neurosci.";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rate(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Dh = ( hinf - h ) / tauh ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauh )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rate ( _threadargscomma_ v ) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauh)))*(- ( ( ( hinf ) ) / tauh ) / ( ( ( ( - 1.0 ) ) ) / tauh ) - h) ;
   }
  return 0;
}
 
static int  rate ( _threadargsprotocomma_ double _lv ) {
   hinf = 1.0 / ( 1.0 + exp ( ( _lv - v_inf_half ) / v_inf_k ) ) ;
   tauh = ( ratetau / ( v_tau_const * ( exp ( ( _lv - v_tau_half1 ) / v_tau_k1 ) + exp ( ( _lv - v_tau_half2 ) / v_tau_k2 ) ) ) ) / qt ;
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
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  eh = _ion_eh;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
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
  eh = _ion_eh;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_h_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_h_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_h_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
 {
   qt = pow( q10 , ( ( 6.3 - 37.0 ) / 10.0 ) ) ;
   v_inf_half = ( v_inf_half_noljp - ljp ) ;
   v_tau_half1 = ( v_tau_half1_noljp - ljp ) ;
   v_tau_half2 = ( v_tau_half2_noljp - ljp ) ;
   rate ( _threadargscomma_ v ) ;
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
  eh = _ion_eh;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   ih = h * gbar * ( v - eh ) ;
   }
 _current += ih;

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
  eh = _ion_eh;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dih;
  _dih = ih;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dihdv += (_dih - ih)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ih += ih ;
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
  eh = _ion_eh;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(h) - _p;  _dlist1[0] = &(Dh) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/new_genemods/ch_Hcn1_md229585.mod";
static const char* nmodl_file_text = 
  "TITLE I-h HCN1 channel from Kamilla Angelo, Michael London,Soren R. Christensen, and Michael Hausser 2007 J. of Neurosci.\n"
  "COMMENT\n"
  "\n"
  "We call it HCN1 as PC express only HCN1 Santoro et al. 2000\n"
  ":aggiunta di correzione per Q10 by ERICA GRANDI\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "COMMENT \n"
  "11 Apr 2021\n"
  "Edits by Suranjana Gupta (SG)\n"
  "The RAGP model does not have any temp. altering mechanisms in place.\n"
  "These mod files have been tested in NEURON (default 6.3 degC), and the\n"
  "integrated working model is being ported to NetPyNE (default 35 degC).\n"
  "To avoid any temp-based discrepancies, 'celsius' has been replaced with 6.3 (degC)\n"
  "(squid temp.)\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX ch_Hcn1_md229585\n"
  "	USEION h READ eh WRITE ih VALENCE 1 \n"
  "	RANGE gbar, hinf,tauh,ratetau,ih\n"
  "	RANGE hinf,tauh,eh\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA) = (milliamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "\n"
  "CONSTANT {\n"
  "	q10=3\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    v 		(mV)\n"
  "    : eh  =-34.4	(mV)        \n"
  "    gbar=.0001 	(mho/cm2)\n"
  "    ratetau = 1 (ms)\n"
  "    rec_temp = 23 (deg) : we set it here at room temperature as in Angelo et al. they forogot tp mention the recording temperature\n"
  "    ljp = 9.3 (mV) : liquid_junction_potential\n"
  "    v_inf_half_noljp = -90.3 (mV)\n"
  "    v_inf_k = 9.67 (mV)\n"
  "    v_tau_const = 0.0018 (1)\n"
  "    v_tau_half1_noljp = -68 (mV)\n"
  "    v_tau_half2_noljp = -68 (mV)\n"
  "    v_tau_k1 = -22 (mv)\n"
  "    v_tau_k2 = 7.14 (mv)\n"
  " }\n"
  "\n"
  "STATE {\n"
  "    h\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    eh (mV)\n"
  "    ih (mA/cm2)\n"
  "    hinf      \n"
  "    tauh\n"
  "    celsius (deg)\n"
  "    v_inf_half (mV)\n"
  "    v_tau_half1 (mV)\n"
  "    v_tau_half2 (mV)\n"
  "    qt\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "\n"
  "    : ADD Q10 correction!!!!! FATTO!!!\n"
  "    :qt = q10^((celsius-37 (degC))/10 (degC))   :SG\n"
  "    qt = q10^((6.3-37 (degC))/10 (degC))        :SG\n"
  "    v_inf_half = (v_inf_half_noljp - ljp)\n"
  "    v_tau_half1 = (v_tau_half1_noljp - ljp)\n"
  "    v_tau_half2 = (v_tau_half2_noljp - ljp)\n"
  "    \n"
  "    rate(v)\n"
  "    h=hinf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    SOLVE states METHOD cnexp\n"
  "    ih = h*gbar*(v-eh)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {  \n"
  "    rate(v)\n"
  "    h' =  (hinf - h)/tauh\n"
  "}\n"
  "\n"
  "PROCEDURE rate(v (mV)) {\n"
  "    : hinf=1/( 1+exp((90+v)/9.67) )\n"
  "    : tauh=ratetau*1/(0.0018*( exp((v+68)/-22) + exp((v+68)/7.14) ))\n"
  "    hinf = 1 / (1+exp( (v-v_inf_half) / v_inf_k) )\n"
  "    tauh = (ratetau / (v_tau_const * ( exp( (v-v_tau_half1) / v_tau_k1) + exp( (v-v_tau_half2) / v_tau_k2) )))/qt\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif

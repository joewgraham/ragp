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
 
#define nrn_init _nrn_init__ch_Cacna1d_md121060
#define _nrn_initial _nrn_initial__ch_Cacna1d_md121060
#define nrn_cur _nrn_cur__ch_Cacna1d_md121060
#define _nrn_current _nrn_current__ch_Cacna1d_md121060
#define nrn_jacob _nrn_jacob__ch_Cacna1d_md121060
#define nrn_state _nrn_state__ch_Cacna1d_md121060
#define _net_receive _net_receive__ch_Cacna1d_md121060 
#define rates rates__ch_Cacna1d_md121060 
#define state state__ch_Cacna1d_md121060 
 
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
#define pmax _p[0]
#define ica _p[1]
#define mtau _p[2]
#define minf _p[3]
#define hinf _p[4]
#define htau _p[5]
#define m _p[6]
#define h _p[7]
#define cai _p[8]
#define cao _p[9]
#define Dm _p[10]
#define Dh _p[11]
#define v _p[12]
#define _g _p[13]
#define _ion_cai	*_ppvar[0]._pval
#define _ion_cao	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _ion_dicadv	*_ppvar[3]._pval
 
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
 static void _hoc_ghk(void);
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
 "setdata_ch_Cacna1d_md121060", _hoc_setdata,
 "ghk_ch_Cacna1d_md121060", _hoc_ghk,
 "rates_ch_Cacna1d_md121060", _hoc_rates,
 0, 0
};
#define ghk ghk_ch_Cacna1d_md121060
 extern double ghk( _threadargsprotocomma_ double , double , double , double );
 /* declare global and static user variables */
#define m_vh m_vh_ch_Cacna1d_md121060
 double m_vh = -33;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "m_vh_ch_Cacna1d_md121060", "mV",
 "pmax_ch_Cacna1d_md121060", "cm/s",
 "ica_ch_Cacna1d_md121060", "mA/cm2",
 "mtau_ch_Cacna1d_md121060", "ms",
 "htau_ch_Cacna1d_md121060", "ms",
 0,0
};
 static double delta_t = 1;
 static double h0 = 0;
 static double m0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "m_vh_ch_Cacna1d_md121060", &m_vh_ch_Cacna1d_md121060,
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
 
#define _cvode_ieq _ppvar[4]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"ch_Cacna1d_md121060",
 "pmax_ch_Cacna1d_md121060",
 0,
 "ica_ch_Cacna1d_md121060",
 "mtau_ch_Cacna1d_md121060",
 "minf_ch_Cacna1d_md121060",
 "hinf_ch_Cacna1d_md121060",
 "htau_ch_Cacna1d_md121060",
 0,
 "m_ch_Cacna1d_md121060",
 "h_ch_Cacna1d_md121060",
 0,
 0};
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 14, _prop);
 	/*initialize range parameters*/
 	pmax = 4.25e-07;
 	_prop->param = _p;
 	_prop->param_size = 14;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 5, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_ca_sym);
 nrn_promote(prop_ion, 1, 0);
 	_ppvar[0]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[1]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pval = &prop_ion->param[4]; /* _ion_dicadv */
 
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

 void _ch_Cacna1d_md121060_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 14, 5);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 4, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 ch_Cacna1d_md121060 /Users/jessicafeldman/Desktop/ragp/ragp/batch_ragp/new_genemods/ch_Cacna1d_md121060.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.78e555060882cp+16, 96485.3}; /* 96485.3321233100141 */
 
#define R _nrnunit_R[_nrnunit_use_legacy_]
static double _nrnunit_R[2] = {0x1.0a1013e8990bep+3, 8.3145}; /* 8.3144626181532395 */
static int _reset;
static char *modelname = "(L-type LVA calcium current for MSP Neuron)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dm = ( minf - m ) / mtau ;
   Dh = ( hinf - h ) / htau ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 Dm = Dm  / (1. - dt*( ( ( ( - 1.0 ) ) ) / mtau )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / htau )) ;
  return 0;
}
 /*END CVODE*/
 static int state (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
    m = m + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / mtau)))*(- ( ( ( minf ) ) / mtau ) / ( ( ( ( - 1.0 ) ) ) / mtau ) - m) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / htau)))*(- ( ( ( hinf ) ) / htau ) / ( ( ( ( - 1.0 ) ) ) / htau ) - h) ;
   }
  return 0;
}
 
double ghk ( _threadargsprotocomma_ double _lv , double _lci , double _lco , double _lz ) {
   double _lghk;
 double _le , _lw ;
 _lw = _lv * ( .001 ) * _lz * FARADAY / ( R * ( celsius + 273.16 ) ) ;
   if ( fabs ( _lw ) > 1e-4 ) {
     _le = _lw / ( exp ( _lw ) - 1.0 ) ;
     }
   else {
     _le = 1.0 - _lw / 2.0 ;
     }
   _lghk = - ( .001 ) * _lz * FARADAY * ( _lco - _lci * exp ( _lw ) ) * _le ;
   
return _lghk;
 }
 
static void _hoc_ghk(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ghk ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   double _lm_alpha , _lm_beta ;
 _lm_alpha = 0.1194 * ( _lv + 8.124 ) / ( exp ( ( _lv + 8.124 ) / 9.005 ) - 1.0 ) ;
   _lm_beta = 2.97 * exp ( _lv / 31.4 ) ;
   mtau = 1.0 / ( _lm_alpha + _lm_beta ) ;
   htau = 14.77 ;
   minf = 1.0 / ( 1.0 + exp ( ( _lv - m_vh ) / - 6.7 ) ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( _lv + 13.4 ) / 11.9 ) ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
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
  cai = _ion_cai;
  cao = _ion_cao;
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
  cai = _ion_cai;
  cao = _ion_cao;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 3, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  m = m0;
 {
   rates ( _threadargscomma_ v ) ;
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
  cai = _ion_cai;
  cao = _ion_cao;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   ica = pmax * m * m * h * ghk ( _threadargscomma_ v , cai , cao , 2.0 ) ;
   }
 _current += ica;

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
  cai = _ion_cai;
  cao = _ion_cao;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dica;
  _dica = ica;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dicadv += (_dica - ica)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ica += ica ;
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
  cai = _ion_cai;
  cao = _ion_cao;
 {   state(_p, _ppvar, _thread, _nt);
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
static const char* nmodl_filename = "/Users/jessicafeldman/Desktop/ragp/ragp/batch_ragp/new_genemods/ch_Cacna1d_md121060.mod";
static const char* nmodl_file_text = 
  "COMMENT\n"
  "11 Apr 2021\n"
  "Edits by Suranjana Gupta (SG): \n"
  "\n"
  "Replaced Ca ion by NEURON's ca ion. Made corresponding changes\n"
  "\n"
  "ghk() present in original code. No changes made\n"
  "ENDCOMMENT\n"
  "\n"
  "\n"
  "TITLE (L-type LVA calcium current for MSP Neuron)\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX ch_Cacna1d_md121060\n"
  "	USEION ca READ cai,cao WRITE ica 				:SG\n"
  "        : USEION Ca WRITE iCa VALENCE 2\n"
  "	:USEION Ca READ Cai,Cao WRITE iCa VALENCE 2		:SG\n"
  "	RANGE minf, mtau, hinf, htau, ica, pmax		:SG -> iCa to ica\n"
  "	GLOBAL m_vh\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mA)	= (milliamp)\n"
  "	(mV)	= (millivolt)\n"
  "	(mM)	= (milli/liter)\n"
  "	:SG\n"
  "	(molar) = (1/liter)\n"
  "	FARADAY = (faraday) (coulomb)	\n"
  "	R = (k-mole) (joule/degC)	: SG -> it is actually J/K-mole but won't compile if units are changed\n"
  "        :FARADAY = 96489 (coul)\n"
  "        :R       = 8.314 (volt-coul/degC)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	v		(mV)\n"
  "	celsius	(degC)\n"
  "	cai  	(mM)		:SG\n"
  "	cao  	(mM)		:SG\n"
  "	:Cai  	(mM)		:SG\n"
  "	:Cao  	(mM)		:SG\n"
  "	pmax = 4.25e-7	(cm/s)\n"
  "	m_vh = -33 (mV)\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	m h\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	:iCa		(mA/cm2)	:SG\n"
  "	ica		(mA/cm2)		:SG\n"
  "	mtau		(ms)\n"
  "	minf\n"
  "	hinf\n"
  "	htau		(ms)\n"
  "}\n"
  "\n"
  "BREAKPOINT { \n"
  "	SOLVE state METHOD cnexp\n"
  "	:iCa = pmax*m*m*h*ghk(v,Cai,Cao,2)		:SG\n"
  "	: iCa = pmax*m*m*h*ghk(v,0.001,Cao,2)\n"
  "	ica = pmax*m*m*h*ghk(v,cai,cao,2)		:SG\n"
  "}\n"
  "\n"
  "DERIVATIVE state {\n"
  "	rates(v)\n"
  "	m'= (minf-m) / mtau\n"
  "	h'= (hinf-h) / htau\n"
  "	}\n"
  "\n"
  "INITIAL {\n"
  "	rates(v)\n"
  "	m = minf\n"
  "	h = hinf\n"
  "}\n"
  "\n"
  "FUNCTION ghk( v(mV), ci(mM), co(mM), z)  (millicoul/cm3) { LOCAL e, w\n"
  "        w = v * (.001) * z*FARADAY / (R*(celsius+273.16))\n"
  "        if (fabs(w)>1e-4) \n"
  "          { e = w / (exp(w)-1) }\n"
  "        else : denominator is small -> Taylor series\n"
  "          { e = 1-w/2 }\n"
  "        ghk = - (.001) * z*FARADAY * (co-ci*exp(w)) * e\n"
  "}\n"
  "\n"
  "UNITSOFF\n"
  "\n"
  "PROCEDURE rates(v(mV)) { LOCAL m_alpha, m_beta\n"
  "	m_alpha = 0.1194*(v+8.124)/(exp((v+8.124)/9.005)-1)\n"
  "	m_beta = 2.97*exp(v/31.4)\n"
  "	mtau = 1/(m_alpha+m_beta)\n"
  "	htau = 14.77\n"
  "	minf = 1 / (1+exp((v-m_vh)/-6.7))\n"
  "	hinf = 1 / (1+exp((v+13.4)/11.9))\n"
  "}\n"
  "\n"
  "UNITSON \n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif

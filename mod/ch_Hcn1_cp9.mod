:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Cellular expression and functional characterization of four hyperpolarization-activated pacemaker channels in cardiac and neuronal tissues. Eur. J. Biochem., 2001, 268, 1646-52

NEURON	{
	SUFFIX ch_Hcn1_cp9
	NONSPECIFIC_CURRENT ihcn
	RANGE gHCN1bar, gHCN1, ihcn, BBiD 
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gHCN1bar = 0.00001 (S/cm2) 
	BBiD = 9 
	ehcn = -45.0 (mV)
}

ASSIGNED	{
	v	(mV)
	ihcn	(mA/cm2)
	gHCN1	(S/cm2)
	mInf
	mTau
}

STATE	{ 
	m
}

BREAKPOINT	{
	SOLVE states METHOD cnexp
	gHCN1 = gHCN1bar*m
	ihcn = gHCN1*(v-ehcn)
}

DERIVATIVE states	{
	rates()
	m' = (mInf-m)/mTau
}

INITIAL{
	rates()
	m = mInf
}

PROCEDURE rates(){
	UNITSOFF 
		mInf = 1.0000/(1+exp((v- -94)/8.1)) 
		mTau = 30.0000
	UNITSON
}

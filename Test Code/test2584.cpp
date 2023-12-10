#if(defined(GLM_PRECISION_HIGHP_DOUBLE))
	typedef highp_dvec2				dvec2;
#elif(defined(GLM_PRECISION_MEDIUMP_DOUBLE))
	typedef mediump_dvec2			dvec2;
#elif(defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef lowp_dvec2				dvec2;
#else
	typedef highp_dvec2				dvec2;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_HIGHP_INT))
	typedef highp_ivec2			ivec2;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_ivec2			ivec2;
#else
	typedef highp_ivec2			ivec2;
#endif//GLM_PRECISION

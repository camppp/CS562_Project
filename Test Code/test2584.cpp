#ifdef GLM_PRECISION_HIGHP_DOUBLE
typedef vec2<double> dvec2;
#elif defined(GLM_PRECISION_MEDIUMP_DOUBLE)
typedef vec2<double> dvec2;
#elif defined(GLM_PRECISION_LOWP_DOUBLE)
typedef vec2<double> dvec2;
#else
typedef vec2<double> dvec2;
#endif

#ifdef GLM_PRECISION_HIGHP_INT
typedef vec2<int> ivec2;
#elif defined(GLM_PRECISION_MEDIUMP_INT)
typedef vec2<int> ivec2;
#elif defined(GLM_PRECISION_LOWP_INT)
typedef vec2<int> ivec2;
#else
typedef vec2<int> ivec2;
#endif

TStr TSqlConn::GetConnStr(
 const TStr& SrvNm, const TStr& DbNm, const TStr& UsrNm, const TStr& PwdStr){
  return TStr()+
   "Server="+SrvNm+";"+"Database="+DbNm+";"+
   "User Id="+UsrNm+";"+"Password="+PwdStr;
}

数据包格式:
	[数据长度,数据]

注意: 
1. 数据长度用字符串(有没有'\0'结束都没有关系)表示，不能超过5个字符

-------------------------------------------------------------------

登陆
{
	"type"		: 0,
	"username"	: "abc", 
	"alias"		: "stevens",			<!-- 可选 -->
	"tags"		: ["home", "school"],	<!-- 可选 -->
}

单发
{
	"type"		: 1,
	"receiver"	: "abc",
	"content"	: "hello"
}


组发
{
	"type"		: 2,
	"tags"		: ["home", "school"],
	"content"	: "hello"
}

群发
{
	"type"		: 3,
	"content"	: "hello"
}

消息
{
	"type"		: 1,		<!-- 对应类型的号码, 1为单发、2为组发、3为群发 -->
	"sender"	: "abc",
	"tag"		: "home",	<!-- 只有组发才会有tag字段 -->
	"content"	: "hello"
}


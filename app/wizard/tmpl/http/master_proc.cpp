#include "stdafx.h"
#include "http_servlet.h"
#include "master_service.h"

////////////////////////////////////////////////////////////////////////////////
// ����������

char *var_cfg_str;
acl::master_str_tbl var_conf_str_tab[] = {
	{ "str", "test_msg", &var_cfg_str },

	{ 0, 0, 0 }
};

int  var_cfg_bool;
acl::master_bool_tbl var_conf_bool_tab[] = {
	{ "bool", 1, &var_cfg_bool },

	{ 0, 0, 0 }
};

int  var_cfg_int;
acl::master_int_tbl var_conf_int_tab[] = {
	{ "int", 120, &var_cfg_int, 0, 0 },

	{ 0, 0 , 0 , 0, 0 }
};

long long int  var_cfg_int64;
acl::master_int64_tbl var_conf_int64_tab[] = {
	{ "int64", 120, &var_cfg_int64, 0, 0 },

	{ 0, 0 , 0 , 0, 0 }
};

////////////////////////////////////////////////////////////////////////////////

master_service::master_service()
{
}

master_service::~master_service()
{
}

void master_service::on_accept(acl::socket_stream* conn)
{
	logger("connect from %s, fd %d", conn->get_peer(),
		conn->sock_handle());

	conn->set_rw_timeout(10);

	acl::memcache_session session("127.0.0.1:11211");
	http_servlet servlet;
	servlet.setLocalCharset("utf-8");  // charset: big5, gb2312, gb18030, gbk, utf-8
	while (true)
	{
		if (servlet.doRun(session, conn) == false)
			break;
	}

	logger("disconnect from %s", conn->get_peer());
}

void master_service::proc_on_init()
{
}

void master_service::proc_on_exit()
{
}

void master_service::do_cgi()
{
        http_servlet servlet;
        servlet.setLocalCharset("utf-8");
        servlet.doRun("127.0.0.1:11211", NULL);
}

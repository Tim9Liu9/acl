#pragma once
#include "acl_cpp/acl_cpp_define.hpp"
#include "acl_cpp/connpool/connect_manager.hpp"

namespace acl
{

/**
 * memcache 客户端请求连接池管理类
 */
class ACL_CPP_API memcache_manager : public acl::connect_manager
{
public:
	memcache_manager();
	virtual ~memcache_manager();

protected:
	/**
	 * 基类纯虚函数，用来创建连接池对象
	 * @param addr {const char*} 服务器监听地址，格式：ip:port
	 * @param count {int} 连接池的大小限制
	 * @param idx {size_t} 该连接池对象在集合中的下标位置(从 0 开始)
	 */
	virtual connect_pool* create_pool(const char* addr, int count,
		size_t idx);
};

} // namespace acl

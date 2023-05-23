#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <memory>
#include <sstream>


#define countof(arg) (sizeof(arg) / sizeof(arg[0]))

#define ASSERT_UNREACHABLE() assert("unreachable code" == 0)

#define UNUSED(expr) do { (void)(expr); } while (0)

#define DISABLE_COPY(classtype) \
    classtype(const classtype&) = delete; \
    classtype& operator=(const classtype&) = delete;


using std::string;


// 交易下单
enum class OrderSide {
    Buy,
    Sell
};

enum class OrderPosSide {
    Net,
    Long,       // 做多
    Short       // 做空
};

enum class OrderType {
    Market,     // 市价单
    Limit       // 限价单
};

enum class TradeMode {
    Isolated,   // 逐仓
    Cross,      // 全仓
    Cash        // 现金
};

struct OrderData {
    string          order_id;
    OrderSide       side;
    OrderPosSide    pos_side;
    string          price;
    string          amount;
    OrderType       order_type = OrderType::Limit;
};

enum class OrderStatus {
    Live,
    Canceled,
    PartiallyFilled,
    Filled,
    Failure,
};


#endif



-- 初始化&更新时自动更新时间：TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP

--用户表
CREATE TABLE user(
    id INTEGER PRIMARY KEY AUTOINCREMENT, 
    usr_id INT UNIQUE NOT NULL, ------用户id 唯一------
    usr_nickname VARCHAR(20) DEFAULT NULL, --用户昵称
    usr_password VARCHAR(255) NOT NULL, --用户密码
    usr_enable INT NOT NULL DEFAULT 1, --是否启用
    usr_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP --注册时间
);

--账户
CREATE TABLE account(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    usr_id INT NOT NULL, --用户id
    act_name VARCHAR(20) UNIQUE NOT NULL, ------账户名称 唯一------
    act_fund REAL DEFAULT 0, --账户金额
    act_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP, --创建时间
    FOREIGN KEY(usr_id) REFERENCES user(usr_id) ON DELETE CASCADE ON UPDATE CASCADE ------级联删除&更新------
);

--账本
CREATE TABLE recocrd(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    usr_id INT NOT NULL, ------用户id------
    act_name VARCHAR(20) NOT NULL, ------账户名称------
    red_datetime TIMESTAMP DEFAULT CURRENT_TIMESTAMP, --记账日期，只在第一次确认记账时间
    red_flowType VARCHAR(10) DEFAULT NULL, --收支流向 收入 支出
    red_classify VARCHAR(20) DEFAULT NULL, --收支分类  医疗\买药
    red_money REAL DEFAULT 0, --收支金额
    red_note TEXT DEFAULT NULL, --备注
    red_image BLOD DEFAULT NULL, --图片
    FOREIGN KEY(usr_id) REFERENCES user(usr_id) ON DELETE CASCADE ON UPDATE CASCADE, ------级联删除&更新------
    FOREIGN KEY(act_name) REFERENCES account(act_name) ON DELETE CASCADE ON UPDATE CASCADE ------级联删除&更新------
);


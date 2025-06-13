package com.test.mapper;

import com.test.entity.Account;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Options;

public interface AccountMapper {

    @Options(useGeneratedKeys = true, keyColumn = "aid", keyProperty = "aid")
    @Insert("insert into account(name, password) values(#{name}, #{password})")
    int addAccount(Account account);



}

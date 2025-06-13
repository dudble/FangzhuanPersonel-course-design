package com.test.mapper;

import com.test.entity.Borrow;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;

public interface BorrowMapper {

    @Insert("insert into borrow(aid, uid) values(#{aid}, #{uid})")
    int insertBorrow(Borrow borrow);

    @Delete("delete from borrow where aid = #{aid} and uid = #{uid}")
    int deleteBorrow(Borrow borrow);

}

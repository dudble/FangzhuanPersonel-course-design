package com.test.mapper;

import com.test.entity.Book;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import java.util.List;

public interface BookMapper {

    @Select("select * from book where uid = #{uid}")
    Book selectBookById(int uid);

    @Select("select * from book where name = #{name}")
    Book selectBookByName(String name);

    @Select("select * from book")
    List<Book> selectBooks();

    @Update("update book set remain = remain-1 where uid = #{uid}")
    int updateSubBook(int uid);

    @Update("update book set remain = remain+1 where uid = #{uid}")
    int updateAddBook(int uid);

}

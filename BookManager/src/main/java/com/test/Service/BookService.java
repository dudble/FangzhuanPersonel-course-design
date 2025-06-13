package com.test.Service;

import com.test.entity.Book;
import com.test.mapper.BookMapper;
import com.test.util.InputUtil;
import com.test.util.SqlUtil;
import org.apache.ibatis.session.SqlSession;

import java.util.List;

public class BookService {

    public static void selectBookById(){

        int id = InputUtil.nextInt("请输入书籍编号");

        try(SqlSession session = SqlUtil.openSession(true)){
            BookMapper mapper = session.getMapper(BookMapper.class);
            Book book = mapper.selectBookById(id);

            System.out.println("书籍编号："+book.getUid());
            System.out.println("书籍名称："+book.getName());
            System.out.println("书籍作者："+book.getAuthor());
            System.out.println("书籍出版商："+book.getPublish());
            System.out.println("剩余数目："+book.getRemain());
        }catch (Exception e){
            System.err.println("该编号可能不存在");
        }

    }
    public static void selectBookByName(){

        InputUtil.nextLine("");////跳过换行符
        String name = InputUtil.nextLine("请输入书籍名称");

        try(SqlSession session = SqlUtil.openSession(true)){
            BookMapper mapper = session.getMapper(BookMapper.class);
            Book book = mapper.selectBookByName(name);
            System.out.println("书籍编号："+book.getUid());
            System.out.println("书籍名称："+book.getName());
            System.out.println("书籍作者："+book.getAuthor());
            System.out.println("书籍出版商："+book.getPublish());
            System.out.println("剩余数目"+book.getRemain());
        }catch (Exception e){
        System.err.println("该编号可能不存在");
    }

    }

    public static void selectAllBook(){
        try(SqlSession session = SqlUtil.openSession(true)){
            BookMapper mapper = session.getMapper(BookMapper.class);
            List<Book> books = mapper.selectBooks();
            if(books.isEmpty()){
                System.out.println("当前没有数据");
            }else{
                for (Book book : books) {
                    System.out.println(book);
                }
            }
        }
    }

}

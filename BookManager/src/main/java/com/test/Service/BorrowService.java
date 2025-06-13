package com.test.Service;

import com.test.entity.Account;
import com.test.entity.Book;
import com.test.entity.Borrow;
import com.test.mapper.BookMapper;
import com.test.mapper.BorrowMapper;
import com.test.util.InputUtil;
import com.test.util.SqlUtil;
import org.apache.ibatis.session.SqlSession;

public class BorrowService {

    public static void selectBorrow(Account account){

        InputUtil.nextLine("");

        int id = InputUtil.nextInt("请输入书籍编号");

        Borrow borrow = new Borrow(account.getAid(), id);

        try(SqlSession session = SqlUtil.openSession(true)){

            BorrowMapper mapper = session.getMapper(BorrowMapper.class);
            BookMapper bookMapper = session.getMapper(BookMapper.class);

            Book book = bookMapper.selectBookById(id);
            if(book.getRemain() == 0){
                System.out.println("非常抱歉，本书已全部借出，请等待他人归还，谢谢");
                return ;
            }

            if(mapper.insertBorrow(borrow) < 1){
                System.out.println("您可能已借得本书");
                return ;
            }
            bookMapper.updateSubBook(id);

            System.out.println("您已成功借得本书，感谢使用");
        } catch (Exception e){
            System.err.println("出借发生错误，您可能已借得本书");
        }

    }


    public static void deleteBorrow(Account account){

        InputUtil.nextLine("");

        int id = InputUtil.nextInt("请输入书籍编号");

        Borrow borrow = new Borrow(account.getAid(), id);

        try(SqlSession session = SqlUtil.openSession(true)){

            BorrowMapper mapper = session.getMapper(BorrowMapper.class);
            BookMapper bookMapper = session.getMapper(BookMapper.class);


            if (mapper.deleteBorrow(borrow) < 1){
                System.out.println("您未借得本书");
                return ;
            }
            bookMapper.updateAddBook(id);


            System.out.println("感谢您及时归还，欢迎您阅读更多书籍");


        } catch (Exception e){
            System.err.println("归还发生错误，您可能未借得本书");
        }

    }










}

package com.test.Service;

import com.test.entity.Account;
import com.test.mapper.AccountMapper;
import com.test.util.InputUtil;
import com.test.util.SqlUtil;
import org.apache.ibatis.session.SqlSession;

import java.sql.*;

public class AccountService {

    private static Account addAccount(){

        String name = InputUtil.nextLine("请输入新账户用户名");
        String password = InputUtil.nextLine("请输入新账户密码");

        Account account = new Account(0, name, password);

        try(SqlSession session = SqlUtil.openSession(true)){
            AccountMapper mapper = session.getMapper(AccountMapper.class);
            int cnt = mapper.addAccount(account);
            if(cnt < 1){
                System.out.println("注册失败，请联系管理员");
            }else {
                System.out.println("欢迎来到图书馆");
            }
            account.setAid(cnt);
            return account;
        }catch (Exception e){
            System.out.println("注册失败，请联系管理员");
        }

        return null;

    }

    public static Account login(){

        System.out.println("欢迎使用图书借阅系统");
        //此处使用jdbc连接，后续为了代码简洁改用mybatis
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/bookdata", "test", "7777777");
             Statement statement = connection.createStatement()) {
            while (true){

                String username = InputUtil.nextLine("请输入用户名，输入-1注册新用户");
                if(username.equals("-1")){

                    return addAccount();

                }

                String password = InputUtil.nextLine("请输入密码");
                ResultSet set = statement.executeQuery(
                        "select * from account where name = '" + username + " 'and password = '" + password + "'");
                if (set.next()) {
                    Account account = new Account(set.getInt(1), set.getString(2), set.getString(3));
                    System.out.println(username + "登录成功");
                    return account;
                } else {
                    System.out.println("用户名或密码错误");

                }
            }


        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }


}

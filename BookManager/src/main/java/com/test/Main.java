package com.test;


import com.test.Service.AccountService;
import com.test.Service.BookService;
import com.test.Service.BorrowService;
import com.test.entity.Account;
import com.test.util.InputUtil;


public class Main {



    private static final String prompt = """
            =========欢迎！=========
            =====您今天想看些什么=====
            
            ====输入1查询书籍信息====
            ======输入2借阅书籍======
            ======输入3归还书籍======
            
            ========输入0退出=======
            """;

    private static final String prompt0 = """
            
            ====输入1查询所有书籍信息====
            ======输入2按书籍名查询======
            =======输入3按编号查询=======
            
            ======输入0返回上级菜单======
            """;

    public static void main(String[] args) {


        Account account = AccountService.login();
        if(account==null) System.exit(0);


        int a = -1;
        while(a != 0){
            a = InputUtil.nextInt(prompt);

            switch (a){
                case 1 -> {
                    int b = -1;
                    while (b != 0) {
                        b = InputUtil.nextInt(prompt0);

                        switch (b) {
                            case 1:
                                BookService.selectAllBook();
                                break;
                            case 2:
                                BookService.selectBookByName();
                                break;
                            case 3:
                                BookService.selectBookById();
                                break;
                        }

                    }
                }

                case 2 -> BorrowService.selectBorrow(account);

                case 3 -> BorrowService.deleteBorrow(account);



            }
        }


    }
}

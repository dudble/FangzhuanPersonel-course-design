package com.test.util;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;

public class SqlUtil {



    private static final SqlSessionFactory factory;

    static {
        try {
             factory = new SqlSessionFactoryBuilder().build(Resources.getResourceAsStream("mybatis-config.xml"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static SqlSession openSession(boolean autoCommit){
        return factory.openSession(autoCommit);
    }

    /*public static SqlSession openSessionBatch(boolean autoCommit){
        return factory.openSession(ExecutorType.BATCH, autoCommit);
    }*/

}

package com.test.entity;


import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class Book {

    private int uid;
    private String name;
    private String author;
    private String publish;
    private int remain;

}

package com.costa.luiz.comics.domain;

public class ComicBook {
    private String title;
    private String author;
    private double price;
    private boolean available;

    public ComicBook(String title, String author, double price, boolean available) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.available = available;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public double getPrice() {
        return price;
    }

    public boolean isAvailable() {
        return available;
    }
}
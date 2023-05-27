

create database bookshop;
use bookshop;
CREATE TABLE AUTHOR (
 author_id INT PRIMARY KEY,
 name VARCHAR(255),
 city VARCHAR(255),
 country VARCHAR(255)
);
CREATE TABLE PUBLISHER (
 publisher_id INT PRIMARY KEY,
 name VARCHAR(255),
 city VARCHAR(255),
 country VARCHAR(255)
);
CREATE TABLE BOOK (
 book_id INT PRIMARY KEY,
 title VARCHAR(255),
 year_of_publication INT,
 author_id INT,
 publisher_id INT,
 FOREIGN KEY (author_id) REFERENCES AUTHOR(author_id),
 FOREIGN KEY (publisher_id) REFERENCES PUBLISHER(publisher_id)
);
CREATE TABLE ORDERS (
 order_id INT PRIMARY KEY,
 quantity INT,
 cost DECIMAL(10, 2),
 date_of_order DATE
);
CREATE TABLE ORDERED_BOOKS (
 order_id INT,
 book_id INT,
 quantity INT,
 FOREIGN KEY (order_id) REFERENCES ORDERS(order_id),
 FOREIGN KEY (book_id) REFERENCES BOOK(book_id)
);
INSERT INTO AUTHOR (author_id, name, city, country)
VALUES (1, 'J.K. Rowling', 'London', 'United Kingdom'),
 (2, 'Stephen King', 'Bangor', 'United States'),
 (3, 'Agatha Christie', 'Torquay', 'United Kingdom'),
 (4, 'Jane Austen', 'Steventon', 'United Kingdom'),
 (5, 'Mark Twain', 'Florida', 'United States'),
 (6, 'Gabriel Garcia Marquez', 'Aracataca', 'Colombia');
INSERT INTO PUBLISHER (publisher_id, name, city, country)
VALUES (1, 'Bloomsbury Publishing', 'London', 'United Kingdom'),
 (2, 'Simon & Schuster', 'New York', 'United States'),
 (3, 'HarperCollins Publishers', 'New York', 'United States'),
 (4, 'Penguin Random House', 'London', 'United Kingdom'),
 (5, 'HarperCollins Publishers', 'London', 'United Kingdom'),
 (6, 'Vintage Books', 'New York', 'United States'),
(7, 'Bloomsbury Publishing', 'London', 'United Kingdom'),
(8, 'Bloomsbury Publishing', 'London', 'United Kingdom');
 
INSERT INTO BOOK (book_id, title, year_of_publication, author_id, publisher_id)
VALUES (1, 'Harry Potter and the Philosopher\'s Stone', 1997, 1, 1),
 (2, 'Carrie', 1974, 2, 2),
 (3, 'Murder on the Orient Express', 1934, 3, 3),
 (4, 'Pride and Prejudice', 1813, 4, 4),
 (5, 'Adventures of Huckleberry Finn', 1884, 5, 5),
 (6, 'One Hundred Years of Solitude', 1967, 6, 6),
 (7, 'The Ink Black Heart', '2022', 1,7),
(8, 'The Magic Beyond Words', '2011', 1,1);
INSERT INTO ORDERS (order_id, quantity, cost, date_of_order)
VALUES (1, 2, 39.98, '2022-02-15'),
 (2, 1, 12.99, '2022-03-05'),
 (3, 3, 29.97, '2022-04-10'),
 (4, 2, 19.98, '2022-04-20');
INSERT INTO ORDERED_BOOKS (order_id, book_id, quantity)
VALUES (1, 1, 2),
 (1, 3, 1),
 (2, 2, 1),
 (3, 4, 1),
 (3, 5, 2),
 (4, 6, 2);
#query-c
SELECT author.name, COUNT(*) AS num_books
FROM author
JOIN book ON author.author_id = book.author_id
GROUP BY author.name
ORDER BY num_books DESC
LIMIT 1;
#query-d
SELECT BOOK.title, BOOK.year_of_publication
FROM BOOK
JOIN publisher ON BOOK.publisher_id = PUBLISHER.publisher_id
WHERE BOOK.year_of_publication = 2011;
#query-e
DELIMITER $$
CREATE TRIGGER check_year_of_publication
BEFORE INSERT ON book
FOR EACH ROW
BEGIN
 IF NEW.year_of_publication <> YEAR(CURDATE()) THEN
 SIGNAL SQLSTATE '45000' 
 SET MESSAGE_TEXT = 'Year of publication must be the current year';
 END IF;
END$$
DELIMITER ;
#query-f
DELIMITER //
CREATE PROCEDURE list_books_by_author_and_year(
 IN author_name VARCHAR(255),
 IN publication_year INT
)
BEGIN
 SELECT book.title, book.year_of_publication
 FROM book
 JOIN author ON book.author_id = author.author_id
 WHERE author.name = author_name AND book.year_of_publication = publication_year;
END //
DELIMITER ;

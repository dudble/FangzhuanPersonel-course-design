/*
 Navicat Premium Dump SQL

 Source Server         : 本地
 Source Server Type    : MySQL
 Source Server Version : 50744 (5.7.44-log)
 Source Host           : localhost:3306
 Source Schema         : bookdata

 Target Server Type    : MySQL
 Target Server Version : 50744 (5.7.44-log)
 File Encoding         : 65001

 Date: 16/06/2025 16:49:30
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account
-- ----------------------------
DROP TABLE IF EXISTS `account`;
CREATE TABLE `account`  (
  `aid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`aid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 51 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of account
-- ----------------------------
INSERT INTO `account` VALUES (1, 'test', '1');
INSERT INTO `account` VALUES (2, 'test2', '123456');
INSERT INTO `account` VALUES (3, '后藤独', '1');
INSERT INTO `account` VALUES (4, '喜多郁代', '123456');
INSERT INTO `account` VALUES (5, '山田凉', '123456');
INSERT INTO `account` VALUES (6, '伊地知虹夏', '123456');
INSERT INTO `account` VALUES (7, '伊地知星歌', '123456');
INSERT INTO `account` VALUES (8, '广井菊里', '123456');
INSERT INTO `account` VALUES (9, '天真=珈百璃=怀特', '123456');
INSERT INTO `account` VALUES (10, '富田美忧', '123456');
INSERT INTO `account` VALUES (11, '泉此方', '123456');
INSERT INTO `account` VALUES (12, '柊镜', '123456');
INSERT INTO `account` VALUES (13, '柊司', '123456');
INSERT INTO `account` VALUES (14, '高良美辛', '123456');
INSERT INTO `account` VALUES (15, '汤浅政明', '123456');
INSERT INTO `account` VALUES (16, '神前晓', '123456');
INSERT INTO `account` VALUES (17, '藤田咲', '123456');
INSERT INTO `account` VALUES (18, '高野麻里佳', '123456');
INSERT INTO `account` VALUES (19, '石原立也', '123456');
INSERT INTO `account` VALUES (20, '武本康弘', '123456');
INSERT INTO `account` VALUES (21, '齐藤圭一郎', '123456');
INSERT INTO `account` VALUES (22, '大田顺飞', '123456');
INSERT INTO `account` VALUES (23, '绪山真寻', '123456');
INSERT INTO `account` VALUES (24, '绪山美波里', '123456');
INSERT INTO `account` VALUES (25, '岁纳京子', '123456');
INSERT INTO `account` VALUES (26, '衫浦绫乃', '123456');
INSERT INTO `account` VALUES (27, '各务原抚子', '123456');
INSERT INTO `account` VALUES (28, '志摩凛', '123456');

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book`  (
  `bid` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `author` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `publish` int(255) NULL DEFAULT NULL,
  `remain` int(4) NOT NULL DEFAULT 233,
  PRIMARY KEY (`bid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of book
-- ----------------------------
INSERT INTO `book` VALUES (1, '深入理解计算机系统', NULL, NULL, 224);
INSERT INTO `book` VALUES (2, '自项而下计算机网络', NULL, NULL, 225);
INSERT INTO `book` VALUES (3, '算法导论', NULL, NULL, 0);
INSERT INTO `book` VALUES (4, '朝鲜王朝500年', NULL, NULL, 233);
INSERT INTO `book` VALUES (5, '太平记', NULL, NULL, 230);
INSERT INTO `book` VALUES (6, '今昔物语集', NULL, NULL, 232);
INSERT INTO `book` VALUES (7, '计算机程序的构造与解释', NULL, NULL, 232);

-- ----------------------------
-- Table structure for borrow
-- ----------------------------
DROP TABLE IF EXISTS `borrow`;
CREATE TABLE `borrow`  (
  `aid` int(11) NOT NULL,
  `bid` int(11) NOT NULL,
  PRIMARY KEY (`aid`, `bid`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of borrow
-- ----------------------------
INSERT INTO `borrow` VALUES (1, 4);
INSERT INTO `borrow` VALUES (2, 2);
INSERT INTO `borrow` VALUES (2, 4);
INSERT INTO `borrow` VALUES (6, 5);
INSERT INTO `borrow` VALUES (6, 6);
INSERT INTO `borrow` VALUES (15, 4);
INSERT INTO `borrow` VALUES (17, 2);
INSERT INTO `borrow` VALUES (25, 7);

-- ----------------------------
-- Table structure for publish
-- ----------------------------
DROP TABLE IF EXISTS `publish`;
CREATE TABLE `publish`  (
  `bid` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  PRIMARY KEY (`bid`, `pid`) USING BTREE,
  INDEX `pid`(`pid`) USING BTREE,
  CONSTRAINT `bid` FOREIGN KEY (`bid`) REFERENCES `book` (`bid`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `pid` FOREIGN KEY (`pid`) REFERENCES `publishing` (`pid`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of publish
-- ----------------------------
INSERT INTO `publish` VALUES (1, 5);
INSERT INTO `publish` VALUES (2, 5);

-- ----------------------------
-- Table structure for publishing
-- ----------------------------
DROP TABLE IF EXISTS `publishing`;
CREATE TABLE `publishing`  (
  `pid` int(11) NOT NULL AUTO_INCREMENT,
  `legal` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`pid`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of publishing
-- ----------------------------
INSERT INTO `publishing` VALUES (1, NULL, '小学馆');
INSERT INTO `publishing` VALUES (2, NULL, '讲谈社');
INSERT INTO `publishing` VALUES (3, NULL, '商务印书馆');
INSERT INTO `publishing` VALUES (4, NULL, '明治书院');
INSERT INTO `publishing` VALUES (5, NULL, '芳文社');
INSERT INTO `publishing` VALUES (6, NULL, '一迅社');

-- ----------------------------
-- View structure for acc_borrowed
-- ----------------------------
DROP VIEW IF EXISTS `acc_borrowed`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `acc_borrowed` AS select `a`.`aid` AS `aid`,`a`.`name` AS `account_name`,`b`.`name` AS `book_name`,`b`.`bid` AS `bid` from ((`account` `a` left join `borrow` on((`borrow`.`aid` = `a`.`aid`))) left join `book` `b` on((`borrow`.`bid` = `b`.`bid`)));

-- ----------------------------
-- Procedure structure for back_book
-- ----------------------------
DROP PROCEDURE IF EXISTS `back_book`;
delimiter ;;
CREATE PROCEDURE `back_book`(aid INT, bid INT)
BEGIN
  #Routine body goes here...
  IF EXISTS(SELECT * FROM borrow WHERE borrow.aid = aid and borrow.bid = bid) THEN
    
    UPDATE book set remain = remain + 1 WHERE book.bid = bid;
    DELETE FROM borrow WHERE borrow.bid = bid and borrow.aid = aid;
    
  END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for borrow_book
-- ----------------------------
DROP PROCEDURE IF EXISTS `borrow_book`;
delimiter ;;
CREATE PROCEDURE `borrow_book`(aid INT, bid INT)
BEGIN
  
  DECLARE rem INT DEFAULT 0;
  
  IF NOT EXISTS(SELECT * FROM borrow WHERE borrow.aid = aid and borrow.bid = bid) THEN
    
    SELECT remain INTO rem FROM book WHERE book.bid = bid;
  
    IF(rem > 0) THEN
    
      UPDATE book set remain = remain - 1 WHERE book.bid = bid;
      INSERT INTO borrow VALUES(aid, bid);
      
    END IF;
  
  END IF;
  
  
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table book
-- ----------------------------
DROP TRIGGER IF EXISTS `del_book`;
delimiter ;;
CREATE TRIGGER `del_book` BEFORE DELETE ON `book` FOR EACH ROW delete from publish where publish.bid = old.bid
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;

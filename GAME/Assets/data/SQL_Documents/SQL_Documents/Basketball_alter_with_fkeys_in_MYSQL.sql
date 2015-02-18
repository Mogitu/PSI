ALTER TABLE `basketball`.`fine` 
ADD CONSTRAINT `member_fine_fk`
  FOREIGN KEY (`membernumber`)
  REFERENCES `basketball`.`member` (`memberno`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE;

ALTER TABLE `basketball`.`member` 
CHANGE COLUMN `postalcode` `postalcode` VARCHAR(7) NOT NULL ,
ADD INDEX `member_team_fk_idx` (`plays_in` ASC),
ADD INDEX `member_team_res_play_fk_idx` (`reserve_player` ASC);

ALTER TABLE `basketball`.`member` 
ADD CONSTRAINT `member_team_fk`
  FOREIGN KEY (`plays_in`)
  REFERENCES `basketball`.`team` (`teamcode`)
  ON DELETE RESTRICT
  ON UPDATE SET NULL,
ADD CONSTRAINT `member_team_res_play_fk`
  FOREIGN KEY (`reserve_player`)
  REFERENCES `basketball`.`team` (`teamcode`)
  ON DELETE RESTRICT
  ON UPDATE SET NULL;


ALTER TABLE `basketball`.`team` 
ADD INDEX `team_captain_fk_idx` (`captain` ASC),
ADD INDEX `team_homehall_fk_idx` (`homehall` ASC);

ALTER TABLE `basketball`.`team` 
ADD CONSTRAINT `team_captain_fk`
  FOREIGN KEY (`captain`)
  REFERENCES `basketball`.`member` (`memberno`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE,
ADD CONSTRAINT `team_homehall_fk`
  FOREIGN KEY (`homehall`)
  REFERENCES `basketball`.`sportshall` (`sportshallname`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE;

ALTER TABLE `basketball`.`game` 
ADD INDEX `game_teamhome_fk_idx` (`teamhome` ASC),
ADD INDEX `game_teamaway_fk_idx` (`teamaway` ASC);

ALTER TABLE `basketball`.`game` 
ADD CONSTRAINT `game_teamhome_fk`
  FOREIGN KEY (`teamhome`)
  REFERENCES `basketball`.`team` (`teamcode`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE,
ADD CONSTRAINT `game_teamaway_fk`
  FOREIGN KEY (`teamaway`)
  REFERENCES `basketball`.`team` (`teamcode`)
  ON DELETE RESTRICT
  ON UPDATE CASCADE;


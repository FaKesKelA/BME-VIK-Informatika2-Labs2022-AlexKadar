use mydb;
-- 9. feladat
insert into oktato values(1, 'Csorba Kristof', 'AUT');
insert into oktato values(2, 'Gemes Kinga', 'AUT');
insert into oktato values(3, 'Vajk Istvan', 'AUT');

insert into tantargy values(1, 'Informatika 2', null);
-- 10. feladat
update tantargy set nev = 'Info 2' where idTantargy = 1;

-- 11. feladat
select * from oktato;

-- 12. feladat
select * from oktato where nev like 'v%';

-- 13. feladat
delete from hallgat where Tantargy_idTantargy = 1;

-- 14. feladat
select * from tantargy where leiras is null;
select * from tantargy;



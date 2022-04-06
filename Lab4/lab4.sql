start transaction;
select * from tag where id=1 for update;
update tag set Maxkolcsonzes=3 where id=1;
commit;
select * from tag where id=1;

select k.*, sz.nemzetiseg, count(sz.id) from konyv k 
inner join konyv_szerzo ksz on ksz.konyvisbn=k.isbn
inner join szerzo sz on sz.id=ksz.szerzoid
group by k.isbn, sz.nemzetiseg;


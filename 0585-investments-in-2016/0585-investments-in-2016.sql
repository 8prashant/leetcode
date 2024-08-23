select round(sum(tiv_2016),2) as tiv_2016 from Insurance as it1 join (
select it3.tiv_2015,it3.lat,it3.lon from Insurance as it3
join (select tiv_2015 from Insurance
group by tiv_2015
having count(tiv_2015)>1) as it4 on it3.tiv_2015=it4.tiv_2015
intersect
select tiv_2015,lat,lon from Insurance
group by lat,lon
having count(pid)=1
) as it2 on it1.lat=it2.lat and it1.lon=it2.lon and it1.tiv_2015=it2.tiv_2015
select sum(tiv_2016) as tiv_2016 from Insurance as it1 join (
select lat,lon from Insurance
group by tiv_2015
having count(tiv_2015)>1
union
select lat,lon from Insurance
group by lat,lon
having count(pid)=1
) as it2 on it1.lat=it2.lat and it1.lon=it2.lon
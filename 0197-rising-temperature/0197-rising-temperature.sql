SELECT W1.ID
FROM Weather W1 JOIN Weather W2 ON DATEDIFF(W1.recordDate ,W2.recordDate )=1 AND W1.temperature>W2.temperature;
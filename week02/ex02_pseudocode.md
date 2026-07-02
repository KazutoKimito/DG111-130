BEGIN โปรแกรม ตรวจสอบเกรด

   INPUT Score

   IF Score >= 80 THEN Grade = "A"

    ELSE IF Score >= 70 THEN Grade = "B"

    ELSE IF Score >= 60 THEN Grade = "C"

    ELSE IF Score >= 50 THEN Grade = "D"

   ELSE Grade = "F"

   END IF

   OUTPUT Grade

END

---



BEGIN โปรแกรม หาค่าสูงสุดจาก 2 ตัวเลข

   INPUT a และ b

   IF a > b THEN Answer = "a คือ ค่าสูงสุด"

    ELSE Answer = "b คือ ค่าสูงสุด"

   END IF

   OUTPUT Answer

END


---

BEGIN โปรแกรม นับจาก 1 ถึง N

กำหนด i = 1

   INPUT N

   WHILE i <= N DO

   PRINT "i"

i = i + 1

   END WHILE

END

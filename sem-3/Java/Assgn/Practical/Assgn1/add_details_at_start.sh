for file in *.java
do
    sed -i  "1s/^/ \/* ===========================================================\n * \n * Roll No: 30\n * \n * File:      $file \n * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)\n * \n * ========================================================== *\/  \n\n /" $file 
    echo "Added Initial Data in: $file"
done

 /* ===========================================================
 * 
 * Roll No: 30
 * 
 * File:      32-roundingError.java 
 * Copyright: 17-Sep-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * ========================================================== */  

 // Show square roots of 1 to 99 and the rounding error.
class SqrRoot {
    public static void main(String args[]) {
        double num, sroot, rerr;

        for (num = 1.0; num < 100.0; num++) {

            sroot = Math.sqrt (num) ;
            System.out.println("Square root of " + num + " is " + sroot);

            rerr = num - (sroot * sroot);
            System.out.println("Rounding error is " + rerr + "\n");
        }
    }
}


/* ===========================================================
Output: 

Square root of 1.0 is 1.0
Rounding error is 0.0

Square root of 2.0 is 1.4142135623730951
Rounding error is -4.440892098500626E-16

Square root of 3.0 is 1.7320508075688772
Rounding error is 4.440892098500626E-16

Square root of 4.0 is 2.0
Rounding error is 0.0

Square root of 5.0 is 2.23606797749979
Rounding error is -8.881784197001252E-16

Square root of 6.0 is 2.449489742783178
Rounding error is 8.881784197001252E-16

Square root of 7.0 is 2.6457513110645907
Rounding error is -8.881784197001252E-16

Square root of 8.0 is 2.8284271247461903
Rounding error is -1.7763568394002505E-15

Square root of 9.0 is 3.0
Rounding error is 0.0

Square root of 10.0 is 3.1622776601683795
Rounding error is -1.7763568394002505E-15

Square root of 11.0 is 3.3166247903554
Rounding error is 0.0

Square root of 12.0 is 3.4641016151377544
Rounding error is 1.7763568394002505E-15

Square root of 13.0 is 3.605551275463989
Rounding error is 1.7763568394002505E-15

Square root of 14.0 is 3.7416573867739413
Rounding error is 0.0

Square root of 15.0 is 3.872983346207417
Rounding error is -1.7763568394002505E-15

Square root of 16.0 is 4.0
Rounding error is 0.0

Square root of 17.0 is 4.123105625617661
Rounding error is 0.0

Square root of 18.0 is 4.242640687119285
Rounding error is 3.552713678800501E-15

Square root of 19.0 is 4.358898943540674
Rounding error is -3.552713678800501E-15

Square root of 20.0 is 4.47213595499958
Rounding error is -3.552713678800501E-15

Square root of 21.0 is 4.58257569495584
Rounding error is 0.0

Square root of 22.0 is 4.69041575982343
Rounding error is 0.0

Square root of 23.0 is 4.795831523312719
Rounding error is 3.552713678800501E-15

Square root of 24.0 is 4.898979485566356
Rounding error is 3.552713678800501E-15

Square root of 25.0 is 5.0
Rounding error is 0.0

Square root of 26.0 is 5.0990195135927845
Rounding error is 3.552713678800501E-15

Square root of 27.0 is 5.196152422706632
Rounding error is 0.0

Square root of 28.0 is 5.291502622129181
Rounding error is -3.552713678800501E-15

Square root of 29.0 is 5.385164807134504
Rounding error is 3.552713678800501E-15

Square root of 30.0 is 5.477225575051661
Rounding error is 0.0

Square root of 31.0 is 5.5677643628300215
Rounding error is 3.552713678800501E-15

Square root of 32.0 is 5.656854249492381
Rounding error is -7.105427357601002E-15

Square root of 33.0 is 5.744562646538029
Rounding error is 0.0

Square root of 34.0 is 5.830951894845301
Rounding error is 0.0

Square root of 35.0 is 5.916079783099616
Rounding error is 0.0

Square root of 36.0 is 6.0
Rounding error is 0.0

Square root of 37.0 is 6.082762530298219
Rounding error is 7.105427357601002E-15

Square root of 38.0 is 6.164414002968976
Rounding error is 7.105427357601002E-15

Square root of 39.0 is 6.244997998398398
Rounding error is 0.0

Square root of 40.0 is 6.324555320336759
Rounding error is -7.105427357601002E-15

Square root of 41.0 is 6.4031242374328485
Rounding error is 0.0

Square root of 42.0 is 6.48074069840786
Rounding error is 0.0

Square root of 43.0 is 6.557438524302
Rounding error is 7.105427357601002E-15

Square root of 44.0 is 6.6332495807108
Rounding error is 0.0

Square root of 45.0 is 6.708203932499369
Rounding error is -7.105427357601002E-15

Square root of 46.0 is 6.782329983125268
Rounding error is 0.0

Square root of 47.0 is 6.855654600401044
Rounding error is 0.0

Square root of 48.0 is 6.928203230275509
Rounding error is 7.105427357601002E-15

Square root of 49.0 is 7.0
Rounding error is 0.0

Square root of 50.0 is 7.0710678118654755
Rounding error is -7.105427357601002E-15

Square root of 51.0 is 7.14142842854285
Rounding error is -7.105427357601002E-15

Square root of 52.0 is 7.211102550927978
Rounding error is 7.105427357601002E-15

Square root of 53.0 is 7.280109889280518
Rounding error is 0.0

Square root of 54.0 is 7.3484692283495345
Rounding error is 0.0

Square root of 55.0 is 7.416198487095663
Rounding error is 0.0

Square root of 56.0 is 7.483314773547883
Rounding error is 0.0

Square root of 57.0 is 7.54983443527075
Rounding error is 0.0

Square root of 58.0 is 7.615773105863909
Rounding error is -7.105427357601002E-15

Square root of 59.0 is 7.681145747868608
Rounding error is 7.105427357601002E-15

Square root of 60.0 is 7.745966692414834
Rounding error is -7.105427357601002E-15

Square root of 61.0 is 7.810249675906654
Rounding error is 7.105427357601002E-15

Square root of 62.0 is 7.874007874011811
Rounding error is 0.0

Square root of 63.0 is 7.937253933193772
Rounding error is -7.105427357601002E-15

Square root of 64.0 is 8.0
Rounding error is 0.0

Square root of 65.0 is 8.06225774829855
Rounding error is 1.4210854715202004E-14

Square root of 66.0 is 8.12403840463596
Rounding error is -1.4210854715202004E-14

Square root of 67.0 is 8.18535277187245
Rounding error is 0.0

Square root of 68.0 is 8.246211251235321
Rounding error is 0.0

Square root of 69.0 is 8.306623862918075
Rounding error is 0.0

Square root of 70.0 is 8.366600265340756
Rounding error is 0.0

Square root of 71.0 is 8.426149773176359
Rounding error is 0.0

Square root of 72.0 is 8.48528137423857
Rounding error is 1.4210854715202004E-14

Square root of 73.0 is 8.54400374531753
Rounding error is 1.4210854715202004E-14

Square root of 74.0 is 8.602325267042627
Rounding error is 0.0

Square root of 75.0 is 8.660254037844387
Rounding error is -1.4210854715202004E-14

Square root of 76.0 is 8.717797887081348
Rounding error is -1.4210854715202004E-14

Square root of 77.0 is 8.774964387392123
Rounding error is -1.4210854715202004E-14

Square root of 78.0 is 8.831760866327848
Rounding error is -1.4210854715202004E-14

Square root of 79.0 is 8.888194417315589
Rounding error is 0.0

Square root of 80.0 is 8.94427190999916
Rounding error is -1.4210854715202004E-14

Square root of 81.0 is 9.0
Rounding error is 0.0

Square root of 82.0 is 9.055385138137417
Rounding error is -1.4210854715202004E-14

Square root of 83.0 is 9.1104335791443
Rounding error is 0.0

Square root of 84.0 is 9.16515138991168
Rounding error is 0.0

Square root of 85.0 is 9.219544457292887
Rounding error is 0.0

Square root of 86.0 is 9.273618495495704
Rounding error is 0.0

Square root of 87.0 is 9.327379053088816
Rounding error is -1.4210854715202004E-14

Square root of 88.0 is 9.38083151964686
Rounding error is 0.0

Square root of 89.0 is 9.433981132056603
Rounding error is 1.4210854715202004E-14

Square root of 90.0 is 9.486832980505138
Rounding error is 0.0

Square root of 91.0 is 9.539392014169456
Rounding error is 0.0

Square root of 92.0 is 9.591663046625438
Rounding error is 1.4210854715202004E-14

Square root of 93.0 is 9.643650760992955
Rounding error is 0.0

Square root of 94.0 is 9.695359714832659
Rounding error is -1.4210854715202004E-14

Square root of 95.0 is 9.746794344808963
Rounding error is 1.4210854715202004E-14

Square root of 96.0 is 9.797958971132712
Rounding error is 1.4210854715202004E-14

Square root of 97.0 is 9.848857801796104
Rounding error is 1.4210854715202004E-14

Square root of 98.0 is 9.899494936611665
Rounding error is 0.0

Square root of 99.0 is 9.9498743710662
Rounding error is 0.0

 =========================================================== */
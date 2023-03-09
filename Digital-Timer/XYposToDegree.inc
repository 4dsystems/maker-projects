//
// Routine to convert X/Y (Relative to 0,0) position into Degrees
// 0 Degrees is straight down to suit rotary objects
//

#DATA
    byte arctan  0,  1,  1,  2,  2,  3,  3,  4,  5,  5,
                 6,  6,  7,  7,  8,  9,  9, 10, 10, 11,
                11, 12, 12, 13, 13, 14, 15, 15, 16, 16,
                17, 17, 18, 18, 19, 19, 20, 20, 21, 21,
                22, 22, 23, 23, 24, 24, 25, 25, 26, 26,
                27, 27, 27, 28, 28, 29, 29, 30, 30, 31,
                31, 31, 32, 32, 33, 33, 33, 34, 34, 35,
                35, 35, 36, 36, 37, 37, 37, 38, 38, 38,
                39, 39, 39, 40, 40, 40, 41, 41, 41, 42,
                42, 42, 43, 43, 43, 44, 44, 44, 44, 45, 45
#END

func XYposToDegree(var curX, var curY)
    var delta, deg, adj ;
    if (curY < 0)
        if (curX < 0)
            adj := 1 ;
            deg := 90 ;
        else
            adj := 2 ;
            deg := 180 ;
        endif
    else
        if (curX < 0)
            deg := 0 ;
            adj := 2 ;
        else
            deg := 270 ;
            adj := 1 ;
        endif
    endif

    curX := ABS(curX) ;
    curY := ABS(curY) ;
    if (curX < curY)
        adj &= 1 ;
    else
        adj &= 2 ;
        SWAP(&curX, &curY) ;
    endif
    delta := arctan[(curX * 100) / curY] ;
    if (adj)
        deg += 90 - delta ;
    else
        deg += delta ;
    endif

    return deg ;
endfunc


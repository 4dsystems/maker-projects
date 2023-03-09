func ledDigitsDisplay(var newval, var index, var left, var Digits, var MinDigits, var WidthDigit, var LeadingBlanks)
    var i, k, l, num[4] ;
    l := 0x500a | (Digits << 8) ;       // UDECxZ
    to(num) ;
    putnum(l, newval) ;
    l := str_Ptr(num) ;
    for (i := 0; i < Digits; i++)
        k := str_GetByte(l++) & 0x0f ;
        if ( LeadingBlanks && (i < Digits - MinDigits) )
            if (k == 0)
                k := 10 ;
            else
                LeadingBlanks := 0 ;
            endif
        endif
        img_SetWord(hndl, index, IMAGE_INDEX, k);
        img_SetWord(hndl, index, IMAGE_XPOS, left+i*WidthDigit) ;
        img_Show(hndl, index);
    next
endfunc
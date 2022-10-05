<?php

function mod_ex( int $base, int $power, int $mod ) {
    $iResult = 1;
    while( $power > 0 ) {
        if( $power & 1 ) {
            $iResult = ( $iResult * $base ) % $mod;
        }
        $base = ( $base * $base ) % $mod;
        $power >>= 1;
    }
    return $iResult;
}

var_dump( mod_ex( 2,6,5 ) );
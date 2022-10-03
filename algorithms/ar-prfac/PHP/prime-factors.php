<?php

$iNumber = 0;

if( !empty($_POST) ) {
    $iNumber = $_POST['number'] ?? 0;
} else if( php_sapi_name() === 'cli' ) {
    // Get the number
    if( isset($argv[1]) ) {
        $iNumber = $argv[1];
    } else {
        return 0;
    }
}

$mFlag = 0;

for( $i = 2; $i < $iNumber; $i++ ) {
    if( $iNumber % $i == 0 ) {
        $iCount = 0;
        for( $j = 1; $j <= $i; $j++ ) {
            if( $i % $j == 0 ) {
                $iCount++;
            }
        }
        if( $iCount == 2 ) {
            if( $mFlag == 0 ) {
                echo "Prime-factors of $iNumber:\n";
                $mFlag = 1;
            }
            echo "$i ";
        }
    }
}

if( $mFlag == 0 )
    echo "There is no valid prime-factorials for $iNumber";
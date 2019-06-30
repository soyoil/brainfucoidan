<?php

class Brainfuck{

  private $code = null;
  private $codePointer = 0;
  private $cell = array();
  private $pointer = 0;
  private $input = null;
  private $inputPointer = 0;
  private $buffer = array();
  private $output = '';
  private $wrap = true;

  public function __construct($code, $input = null, $wrap = null){
    $this->code = $code;
    $this->input = ($input) ? $input : null;
    $this->wrap = (boolean) $wrap;
  }

  public function run($return = false){
    while ($this->codePointer < strlen($this->code)) {
      
    }
  }

}
# Steps for setting up the EOS 
**June 12, 2018**

## Pre-requisite
This is for enabling your system to run EOS Smart contracts (SC). This is for Installation on Linux (Ubuntu). 
  
  Steps:
    
   * open cmd.
   * ```>pushd directory-where-eos-folder-is-to-be-kept```
   * ```>bash```
   * Now, you are ready with following the steps below.
  
## Installation
* ### Cloning the github repository
  Command - 
  
  ```$ git clone https://github.com/EOSIO/eos.git --recursive```
  
  ![](https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_.png)

* ### goto the ```eos``` folder
  In cmd, enter ```$cd eos```
  
  ![](https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_2.png)
  
* ### submodule check
  ```$git submodule update --init --recursive```
  
  NO IMAGE
  
* ### Latest version
  Goto  - https://github.com/EOSIO/eos/releases/latest
  
  It will take you to the latest release version page (e.g. v1.0.3, v1.0.2, v1.0.1, etc). Get the version no. from here. 
  
  ```$git checkout tags/v1.0.3```
  
  ![](https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_3.png)

* ### Building the tools for eos-dev
  ```$./eosio_build.sh
  
 ![](https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_4.png)
  
## REFERENCE
* EOS v1.0 setup - https://www.youtube.com/watch?v=CbczJDA6cik

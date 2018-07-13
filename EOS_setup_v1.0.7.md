# EOS Setup v1.0.7
This is the next tutorial based on the Setup of EOSIO on a system.
[**Previous Tutorial**](https://github.com/abhi3700/My_Learning_EOS/blob/master/EOS_setup.md)

## Commands with Screenshots 
1. ### Cloning the repository - 
    ```$ git clone https://github.com/EOSIO/eos.git --recursive```
<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_1.png" width="550" height="300">
</p>

2. ### Entering into the eos folder - 
    ```$ cd eos```

3. ### Update the submodule/branches - 
    ```$ git submodule update --init --recursive```
   
4. ### Check the required tag availability - 
    ```$ git checkout tags/v1.0.7```
  
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_2.png" width="550" height="230">
</p>

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_3.png" width="550" height="380">
</p>
  
   #### NOTE: the head of the repository is 90fefdd...... , which is identical to the one mentioned in the cmd.
    
5. ### Dependencies and EOSIO Installation - 
    ```$ ./eosio_build.sh```
  
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_4.png" width="550" height="400">
</p>

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_5.png" width="550" height="400">
</p>


  Things to be done - 
  * Current head in the repository - 90fefdd...... 
  * Architecture check
  * Installed dependencies check
  * dpkg dependencies check - boost library, MongoDB, MongoDB C++ driver, secp256kl-zkp,  LLVM with WASM support.
  * EOSIO installation
  
  <p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_6.png" width="550" height="370">
</p>

6. ### After the installation is DONE, check the CLI commands - ```eosiocpp``` , ```cleos``` , ```keosd``` , ```nodeos``` 

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_7.png" width="550" height="230">
</p>

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_8.png" width="550" height="330">
</p>

<p align="center">
  <img src="https://github.com/abhi3700/My_Learning_EOS/blob/master/Images/eos_setup_v2_9.png" width="550" height="330">
</p>

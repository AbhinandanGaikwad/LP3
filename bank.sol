// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract bank{
    address private accOwner;
    uint256 balance;

    constructor(){
        accOwner = msg.sender;
    }

    function Deposit() public payable {
        require(accOwner == msg.sender,"You are not the Owner of the Account");
        require(msg.value > 0,"Amount should be greater than 0");
        balance += msg.value;
    }

    function Withdraw() public payable {
        require(accOwner == msg.sender,"You are not the Owner of Account");
        require(msg.value <= balance,"Amount should be less than balance");
        balance -= msg.value;
    }

    function showBalance() public view returns(uint256){
        require(accOwner==msg.sender,"You are not an account owner"); 
        return balance;
    } 
}

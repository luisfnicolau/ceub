-- Exercicio de DDL
-- 23-02-2026

-- 1. Criar o banco de dados
CREATE DATABASE bd_rh_0101;

-- 2. Usar o banco de dados
USE bd_rh_0101;

-- 3. Criar tabelas
CREATE TABLE tb_cargo
(cd_cargo INT NOT NULL PRIMARY KEY, cargo CHAR(30));

CREATE TABLE tb_setor
(cd_setor INT NOT NULL PRIMARY KEY,
setor CHAR(30));

CREATE TABLE tb_funcionario
(matricula INT NOT NULL PRIMARY KEY,
funcionario CHAR(50),
dt_nascimento DATE,
cd_setor INT,
cd_cargo INT,
salario DECIMAL(8,2));

-- relacionamento

ALTER TABLE tb_funcionario ADD CONSTRAINT fk_cargo FOREIGN KEY (cd_cargo) REFERENCES tb_cargo(cd_cargo);

ALTER TABLE tb_funcionario ADD CONSTRAINT fk_setor FOREIGN KEY (cd_setor) REFERENCES tb_setor(cd_setor);
-- Exercicio de DDL 
-- 23-02-2026 

-- apagar o banco de dados 
-- drop database bd_rh_0101; 

-- 1 criar o banco de dados 
create database bd_rh_0101; 

-- 2 usar o banco de dados 
use bd_rh_0101; 

-- 3 criar tabelas
create table tb_cargo
(cd_cargo int not null primary key, 
cargo char(30)); 

-- 4 tb setor
create table tb_setor
(cd_setor int not null primary key, 
setor char(30));

-- 5 tb_funcionario 
create table tb_funcionario 
(matricula int not null primary key, 
funcionario char(50),
dt_nascimento date, 
cd_setor int, 
cd_cargo int, 
salario decimal(8,2));

-- relacionamento 
alter table tb_funcionario 
add constraint fk_cargo foreign key (cd_cargo) 
references tb_cargo (cd_cargo);

alter table tb_funcionario 
add constraint fk_setor foreign key (cd_setor) 
references tb_setor (cd_setor);


-- popular o banco de dados 

insert into tb_setor (cd_setor, setor) 
values 
(1, 'Enfermaria'),
(2, 'Administracao'),
(3, 'Informatica'),
(4, 'Engenharia'),
(5, 'Juridico'),
(6, 'Logistica'),
(7, 'Presidencia');


select * from tb_setor;

insert into tb_cargo 
(cd_cargo, cargo) 
values 
(1, 'Enfermeiro(a)'),
(2, 'Administrador(a)') ,
(3, 'Analista') ,
(4, 'Engenheiro(a)') ,
(5, 'Advogado(a)') ,
(6, 'Gerente') ,
(7, 'Executivo(a)') ;

select * from tb_cargo; 

insert into tb_funcionario  
(matricula, funcionario,  dt_nascimento, cd_setor, cd_cargo, salario)
Values  
(1,'Ana Clara', '1977-07-05',  5, 1, 3000),
(2,'Patricia Azevedo', '1944-07-04', 1, 1, 4000),
(3,'Jose Maria', '1971-05-10', 3, 1, 6000),
(4,'Sonia Abrantes', '1979-05-29',  4, 1, 7000), 
(5,'Valdir Reinaldo', '1960-09-22',  2, 2, 16000), 
(6,'Jose Alberto', '1955-01-13',  2, 2, 15000);

select * from tb_funcionario; 

-- delete 
delete from tb_cargo 
where cd_cargo = 1; 

-- Exercicio 

-- 1)  Listar  a cd_setor = 2  na tabela tb_funcionário

select * from tb_funcionario 
where cd_setor = 2; 
-- 2)  Excluir cd_cargo  = 1 na tabela tb_cargo

delete from tb_cargo 
where cd_cargo = 1; 

-- 3)  Alterar na tabela tb_funcionario  matricula = 1  salario (6000)

update tb_funcionario 
set salario = 6000
where matricula = 1; 

select * from tb_funcionario; 

-- 4)  Listar a tabela (tb_funcionario)  salario > 5000

select * from tb_funcionario 
where salario > 5000; 






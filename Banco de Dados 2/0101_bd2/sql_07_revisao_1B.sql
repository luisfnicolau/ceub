create database bd_revisao_0101;
use bd_revisao_0101;

create table tb_cliente
(
cd_cliente int not null primary key,
cliente varchar(50)
);

create table tb_vendedor
(
cd_vendedor int not null primary key,
vendedor varchar(50)
);

create table tb_veiculo
(
cd_veiculo int not null primary key,
veiculo char(50),
valor_veiculo decimal(12,2)
);

create table tb_pedido(
dt_pedido date not null,
cd_veiculo int not null,
cd_vendedor int not null,
cd_cliente int not null,
nr_pedido int,
valor_pedido decimal (12,2),
comissao decimal (12,2),
primary key (dt_pedido, cd_veiculo, cd_vendedor, cd_cliente)
);

alter table tb_pedido
add constraint fk_cliente foreign key (cd_cliente)
references tb_cliente(cd_cliente);

alter table tb_pedido
add constraint fk_vendedor foreign key (cd_vendedor)
references tb_vendedor(cd_vendedor);

alter table tb_pedido
add constraint fk_veiculo foreign key (cd_veiculo)
references tb_veiculo(cd_veiculo);

-- Comandos DDL
create table tb_teste
(
cd_teste int not null primary key,
teste char(30)
);

alter table tb_teste
add nota int;

alter table tb_teste
modify column nota char(50);

alter table tb_teste
drop column nota;

drop table tb_teste;


-- vendedor

select * from tb_vendedor;

Insert into tb_vendedor
(cd_vendedor, vendedor)
Values
(1, 'Anibal'),
(2, 'Antonio de Moraes'), 
(3, 'Barbara Alcantara'), 
(4, 'Deise Castro'),
(5, 'Eider Nascimento');


-- cliente
select * from tb_cliente; 

Insert into tb_cliente
(cd_cliente, cliente) 
Values 
(1, 'Vallu Nascimento'),
(2, 'Rogeria Negreti'),
(3, 'Henrique Silva'),
(4, 'Wellington Alves'),
(5, 'Jose Pereira');

-- veiculo
select * from tb_veiculo; 

Insert into tb_veiculo
(cd_veiculo, veiculo, valor_veiculo) 
Values
(1, 'Onix', 52000),
(2, 'Prisma', 49000),
(3, 'S10', 109000),
(4, 'Cruze', 101000),
(5, 'Spin', 69000),
(6, 'Cobalt', 63000);

-- Pedido 

select * from tb_pedido;

insert into tb_pedido
(nr_pedido, dt_pedido, cd_veiculo, cd_cliente, cd_vendedor, valor_pedido,comissao)
values
(1,'2019-01-10',1,2,3,52000,0),
(2,'2019-02-20',2,3,4,49000,0),
(3,'2019-03-30',3,4,5,109000,0),
(4,'2019-04-10',4,5,1,101000,0),
(5,'2019-05-20',5,5,1,69000,0),
(6,'2019-06-30',6,1,2,63000,0),
(7,'2019-07-10',1,4,5,52000,0),
(8,'2019-08-20',1,4,5,52000,0),
(9,'2019-09-30',1,4,5,52000,0),
(10,'2019-10-10',1,4,5,52000,0);

-- 1 Incluir cliente Pedro Nóbrega
insert into tb_cliente
(cd_cliente, cliente)
values
 (6, "Pedro Nóbrega");
  
-- 2 Alterar cliente Vallu Nascimento para Carlos Nascimento na tabela cliente
update tb_cliente set cliente="Carlos Nascimento" where cliente="Vallu Nascimento";

-- 3 Alterar vendedor Anibal para Anibal Santoro
update tb_vendedor set vendedor="Anibal Santoro" where vendedor="Anibal";

-- 4 Alterar o valor do Pedido 1 parar cd_veiculo 4 e valor R$101.000,00
update tb_pedido set cd_veiculo=4, valor_pedido=101000.00 where nr_pedido=1;
-- 5 Excluir Cliente quando o cd_cliente = 1  (vê se é possível ? Explique ? )
select * from tb_cliente;
select * from tb_pedido;

delete from tb_cliente where cd_cliente=1;

-- 6 Atualizar o valor da comissão em 10% do valor da venda
update tb_pedido
set comissao = valor_pedido * 0.1
where comissao != valor_pedido * 0.1;

-- 7 lista os valores que o campo de cd_veiculo tem na tb_pedido
select distinct cd_veiculo from tb_pedido;
-- 8 acrescenta o campo nota int na tb_pedido
alter table tb_pedido add nota int;
-- 9 modifica o campo nota int para nota char(50) na tb_pedido  
alter table tb_pedido modify column nota char(50);
-- 10 exclui o campo nota na tb_pedido
alter table tb_pedido drop column nota;

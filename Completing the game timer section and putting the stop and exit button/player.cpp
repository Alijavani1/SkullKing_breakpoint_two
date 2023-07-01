#include "player.h"

player::player()
{
    turn = 1;
    predict_win = 0;
    coin = 1000;
    win = 0;
    lose = 0;
    start = 0;
    nobat=0;
    takeWin = 0;
    point=0;
    pointOpponent=0;
    clickPlay=0;
    stop=0;
}
QString player:: get_usernameOpponent(){
    return usernameOpponent;
}
void player:: set_usernameOpponent(QString a){
    usernameOpponent=a;
}
player::player( const player&c){
    username=c.username;
    password=c.password;
    phoneNumber=c.phoneNumber;
    profile=c.profile;
    coin=c.coin;
    win=c.win;
    lose=c.lose;
    turn=c.turn;
    role=c.role;
    clickPlay=c.clickPlay;
    point=c.point;
    pointOpponent = c.pointOpponent;
    nobat = c.nobat;
    countCard = c.countCard;
    predict_win=c.predict_win;
     start=c.start;
     takeWin=c.takeWin;
     playerCard=c.playerCard;
     winCard=c.winCard;
      playedCard=c.playedCard;
      stop=c.stop;
}
player::~player(){}
void player:: set_playerCard(card c) {
    playerCard.push_back(c);
}
QString player:: get_clickPlay(){
    return clickPlay;
}
void player:: set_clickPlay(QString a){
    clickPlay=a;
}

QList<card>&player:: get_playerCards() {
    return playerCard;
}
void player:: set_winCard(card c) {
    winCard.push_back(c);
}
QList<card> & player::get_winCards() {
    return winCard;
}
void player:: delete_playCard() {
   playerCard.clear();
}
//start
void player:: set_start(int s) {
    start = s;
}
int player:: get_start() {
    return start;
}
//nobat
void player::set_nobat(int n){
    nobat = n;
}
int player::get_nobat(){
    return nobat;
}
//time
void player:: set_time(int t){
    time = t;
}
int player:: get_time(){
    return time;
}

void player:: set_countCard(int n){
    countCard = n;
}
int player:: get_countCard()
{
    return countCard;
}
//username
void player:: set_username(QString s) {
    username = s;
}
QString player:: get_username() {
    return username;
}
//password
void player:: set_password(QString s) {
    password = s;
}
QString player:: get_password() {
    return password;
}
//phone
void player:: set_phoneNumber(QString s) {
    phoneNumber = s;
}
QString player:: get_phoneNumber() {
    return phoneNumber;
}
//profile
void player:: set_profile(QString s) {
    profile = s;
}
QString player:: get_profile() {
    return profile;
}
//win
void player:: set_win(int s) {
    win = s;
}
int player:: get_win() {
    return win;
}
//lose
void player:: set_lose(int s) {
    lose = s;
}
int player:: get_lose() {
    return lose;
}
//predictWin
void player:: set_predict_win(int s) {
    predict_win = s;
}
int player:: get_predict_win() {
    return predict_win;
}
//
void player:: set_turn(int s) {
    turn = s;
}
int player:: get_turn() {
    return turn;
}
//takeWin
void player:: set_takeWin(int s) {
    takeWin = s;
}
int & player:: get_takeWin() {
    return takeWin;
}
//coin
void player:: set_coin(long int s) {
    coin = s;
}
long int player:: get_coin() {
    return coin;
}
//playedCard
void player:: set_playedCard(card c) {
    playedCard = c;
}
int player:: get_stop(){
    return stop;
}
void player:: set_stop(int a){
stop=a;
}
card player:: get_playedCard() {
    return playedCard;
}
QTextStream &operator >>(QTextStream& in, player &p){
    in >> p.username>>p.password>>p.phoneNumber>>p.coin>>p.win>>p.lose;
    return in;
}
QTextStream &operator <<(QTextStream& out,const player &p){
    out<<p.username<<" "<<p.password<<" "<<p.phoneNumber<<" "<<p.coin<<" "<<p.win<<" "<<p.lose;
    return out;
}
card player:: get_stratCard(){
    return startCard;
}
void player:: set_StratCard(card a){
    startCard=a;
}
QString player:: get_role(){
    return role;
}
void player:: set_role(QString a){
    role=a;
}
void  player:: set_playcardOpponent(card a){
    playcardOpponent=a;
}
card player:: get_playcardOpponent(){
    return playcardOpponent;
}
void player:: set_point(long int a){
    point=a;
}
long int player:: get_point(){
    return point;
}
void player:: set_pointOpponent(int long a){
    pointOpponent=a;
}
long int player:: get_pointOpponent(){
    return pointOpponent;
}

QVector<player> filePlayer;
player gPlayer;

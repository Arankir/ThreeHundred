#include "card.h"

Card::Card(QObject *aParent) : QObject(aParent), currentDenomination_(Denomination::unknown), currentSuit_(Suit::unknown), currentImage_(QPixmap()){

}

Card::Card(Denomination aDenomination, Suit aSuit, QObject *aParent) : QObject(aParent), currentDenomination_(aDenomination), currentSuit_(aSuit) {
    currentImage_ = QPixmap("://" + suitToString(currentSuit_) + "/" + denominationToString(currentDenomination_) + ".png");
    rect_ = QRectF(0,0,width_,height_);
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    borderTimer_.setInterval(100);
    borderTimer_.start();
    connect(&borderTimer_, &QTimer::timeout, this, &Card::updatePen);
}

QRectF Card::boundingRect() const {
    return QRectF(rect_);
}

void Card::paint(QPainter *aPainter, const QStyleOptionGraphicsItem *aOption, QWidget *aWidget) {
    if(change_){
        change_ =false;
        QPen pen;
        pen.setWidthF(std::rand()%3);
        aPainter->setPen(pen);
    }
    aPainter->drawPixmap(rect_.x(),rect_.y(),rect_.width(),rect_.height(), currentImage_.scaled(rect_.width(), rect_.height()));
    aPainter->drawRoundedRect(rect_.x(),rect_.y(),rect_.width(),rect_.height(),5,5);
}


void Card::setSize(QSize aSize) {
    width_ = aSize.width();
    height_ = aSize.height();
}

Denomination Card::getDenomination() {
    return currentDenomination_;
}

Suit Card::getSuit() {
    return currentSuit_;
}

QString Card::getTextCard() {
    return denominationToString(currentDenomination_) + " of " + suitToString(currentSuit_);
}

int Card::getCardScore() {
    switch (currentDenomination_) {
    case Denomination::six: {
        return 6;
    }
    case Denomination::seven: {
        return 7;
    }
    case Denomination::eight: {
        return 8;
    }
    case Denomination::nine: {
        return 9;
    }
    case Denomination::ten: {
        return 10;
    }
    case Denomination::jack: {
        return 2;
    }
    case Denomination::queen: {
        return 30;
    }
    case Denomination::king: {
        switch (currentSuit_) {
        case Suit::spades: {
            return 40;
        }
        default: {
            return 4;
        }
        }
    }
    case Denomination::ace: {
        return 11;
    }
    default: {
        return 0;
    }
    }
}

QPixmap Card::getPixmap() {
    return currentImage_;
}

QRectF Card::geometry() const
{
    return rect_;
}

void Card::setGeometry(const QRectF &value)
{
    if(rect_!=value){
        rect_=value;
        QPointF np = mapToScene(QPointF(rect_.x(),rect_.y()));
        setPos(np);
    }
}

bool Card::isExist() {
    return (currentSuit_ != Suit::unknown) && (currentDenomination_ != Denomination::unknown);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *aEvent)
{
    mStartMovePos_ = aEvent->pos();
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *aEvent)
{
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *aEvent)
{
    int distance = ((aEvent->pos() - mStartMovePos_)).manhattanLength();
      if(distance > QApplication::startDragDistance())
      {
        QPointF np = mapToScene(aEvent->pos() - mStartMovePos_);

        if( (np.x() < 0) || (np.y() < 0) )
          return;
        if( (np.x() > 800) || (np.y() > 800) )
          return;

          this->setPos(np);
      }
}

void Card::hoverEnterEvent(QGraphicsSceneHoverEvent *aEvent)
{
     qDebug()<<"shiet";
     qDebug() << pos();
     qDebug()<< x()<<y();
     mHover_=true;
     //QGraphicsItem::update();
    //this->setPos(QPointF(150,150));
     QPropertyAnimation *cardPosAnim= new QPropertyAnimation(this, "pos");
     cardPosAnim->setStartValue(QPointF(x(),y()));
     cardPosAnim->setEndValue(QPointF(x(),y()-50));
     cardPosAnim->setDuration(1000);
     cardPosAnim->setEasingCurve(QEasingCurve::OutBack);
     cardPosAnim->start(QAbstractAnimation::DeleteWhenStopped);
}

void Card::hoverLeaveEvent(QGraphicsSceneHoverEvent *aEvent)
{
    qDebug()<<"leave";
    mHover_=false;
    QPropertyAnimation *cardPosAnim= new QPropertyAnimation(this, "pos");
    cardPosAnim->setStartValue(QPointF(x(),y()));
    cardPosAnim->setEndValue(QPointF(x(),y()+50));
    cardPosAnim->setDuration(1000);
    cardPosAnim->setEasingCurve(QEasingCurve::OutBack);
    cardPosAnim->start(QAbstractAnimation::DeleteWhenStopped);
//    this->setGeometry(QRectF(rect_.x(),rect_.y()+5,rect_.width(),rect_.height()));
//    QGraphicsItem::update();
    qDebug() << pos();
}

Card::Card(const Card &aCard) : QObject(aCard.parent()), currentDenomination_(aCard.currentDenomination_), currentSuit_(aCard.currentSuit_), currentImage_(aCard.currentImage_) {

}

Card &Card::operator=(const Card &aCard) {
    currentSuit_            = aCard.currentSuit_;
    currentDenomination_    = aCard.currentDenomination_;
    currentImage_           = aCard.currentImage_;
    return *this;
}

QPointF Card::pos() const
{
    return m_pos;
}

void Card::setPos(QPointF pos)
{
    moveBy(pos.x()-m_pos.x(),pos.y()-m_pos.y());
    m_pos = pos;
}

void Card::setPos(float x, float y)
{
    moveBy(x-m_pos.x(),y-m_pos.y());
    m_pos = QPointF(x,y);
}

void Card::updatePen()
{
    change_ = true;

    update();
}

void Card::setBlurRadius(int)
{

}

QString denominationToString(Denomination aDenomination) {
    switch (aDenomination) {
    case Denomination::six: {
        return "six";
    }
    case Denomination::seven: {
        return "seven";
    }
    case Denomination::eight: {
        return "eight";
    }
    case Denomination::nine: {
        return "nine";
    }
    case Denomination::ten: {
        return "ten";
    }
    case Denomination::jack: {
        return "jack";
    }
    case Denomination::queen: {
        return "queen";
    }
    case Denomination::king: {
        return "king";
    }
    case Denomination::ace: {
        return "ace";
    }
    default: {
        return "unknown";
    }
    }
}

QString suitToString(Suit aSuit) {
    switch (aSuit) {
    case Suit::hearts: {
        return "hearts";
    }
    case Suit::diamonds: {
        return "diamonds";
    }
    case Suit::spades: {
        return "spades";
    }
    case Suit::clubs: {
        return "clubs";
    }
    default: {
        return "unknown";
    }
    }
}

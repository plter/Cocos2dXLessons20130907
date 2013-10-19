//
//  PSprite.cpp
//  HelloBox2D
//
//  Created by plter on 13-10-19.
//
//

#include "PSprite.h"

#include "support/CCPointExtension.h"

#include "Box2D.h"

PSprite::PSprite()
: m_bIgnoreBodyRotation(false)
, m_pB2Body(NULL)
, m_fPTMRatio(0.0f)
{}

PSprite* PSprite::create()
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::createWithTexture(CCTexture2D *pTexture)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithTexture(pTexture))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::createWithTexture(CCTexture2D *pTexture, const CCRect& rect)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithTexture(pTexture, rect))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithSpriteFrame(pSpriteFrame))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::createWithSpriteFrameName(const char *pszSpriteFrameName)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithSpriteFrameName(pszSpriteFrameName))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::create(const char *pszFileName)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

PSprite* PSprite::create(const char *pszFileName, const CCRect& rect)
{
    PSprite* pRet = new PSprite();
    if (pRet && pRet->initWithFile(pszFileName, rect))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

// this method will only get called if the sprite is batched.
// return YES if the physic's values (angles, position ) changed.
// If you return NO, then nodeToParentTransform won't be called.
bool PSprite::isDirty()
{
    return true;
}

bool PSprite::isIgnoreBodyRotation() const
{
    return m_bIgnoreBodyRotation;
}

void PSprite::setIgnoreBodyRotation(bool bIgnoreBodyRotation)
{
    m_bIgnoreBodyRotation = bIgnoreBodyRotation;
}

// Override the setters and getters to always reflect the body's properties.
const CCPoint& PSprite::getPosition()
{
    updatePosFromPhysics();
    return CCNode::getPosition();
}

void PSprite::getPosition(float* x, float* y)
{
    updatePosFromPhysics();
    return CCNode::getPosition(x, y);
}

float PSprite::getPositionX()
{
    updatePosFromPhysics();
    return m_obPosition.x;
}

float PSprite::getPositionY()
{
    updatePosFromPhysics();
    return m_obPosition.y;
}

b2Body* PSprite::getB2Body() const
{
    return m_pB2Body;
}

void PSprite::setB2Body(b2Body *pBody)
{
    m_pB2Body = pBody;
}

float PSprite::getPTMRatio() const
{
    return m_fPTMRatio;
}

void PSprite::setPTMRatio(float fRatio)
{
    m_fPTMRatio = fRatio;
}

// Override the setters and getters to always reflect the body's properties.
void PSprite::updatePosFromPhysics()
{
    b2Vec2 pos = m_pB2Body->GetPosition();
    float x = pos.x * m_fPTMRatio;
    float y = pos.y * m_fPTMRatio;
    m_obPosition = ccp(x,y);
}

void PSprite::setPosition(const CCPoint &pos)
{
    float angle = m_pB2Body->GetAngle();
    m_pB2Body->SetTransform(b2Vec2(pos.x / m_fPTMRatio, pos.y / m_fPTMRatio), angle);
}

float PSprite::getRotation()
{
    return (m_bIgnoreBodyRotation ? CCSprite::getRotation() :
            CC_RADIANS_TO_DEGREES(m_pB2Body->GetAngle()));
}

void PSprite::setRotation(float fRotation)
{
    if (m_bIgnoreBodyRotation)
    {
        CCSprite::setRotation(fRotation);
    }
    else
    {
        b2Vec2 p = m_pB2Body->GetPosition();
        float radians = CC_DEGREES_TO_RADIANS(fRotation);
        m_pB2Body->SetTransform(p, radians);
    }
}

// returns the transform matrix according the Box2D Body values
CCAffineTransform PSprite::nodeToParentTransform()
{
    b2Vec2 pos  = m_pB2Body->GetPosition();
	
	float x = pos.x * m_fPTMRatio;
	float y = pos.y * m_fPTMRatio;
	
	if (m_bIgnoreAnchorPointForPosition)
    {
		x += m_obAnchorPointInPoints.x;
		y += m_obAnchorPointInPoints.y;
	}
	
	// Make matrix
	float radians = m_pB2Body->GetAngle();
	float c = cosf(radians);
	float s = sinf(radians);
	
	// Although scale is not used by physics engines, it is calculated just in case
	// the sprite is animated (scaled up/down) using actions.
	// For more info see: http://www.cocos2d-iphone.org/forum/topic/68990
	if (!m_obAnchorPointInPoints.equals(CCPointZero))
    {
		x += ((c * -m_obAnchorPointInPoints.x * m_fScaleX) + (-s * -m_obAnchorPointInPoints.y * m_fScaleY));
		y += ((s * -m_obAnchorPointInPoints.x * m_fScaleX) + (c * -m_obAnchorPointInPoints.y * m_fScaleY));
	}
    
	// Rot, Translate Matrix
	m_sTransform = CCAffineTransformMake( c * m_fScaleX,	s * m_fScaleX,
									     -s * m_fScaleY,	c * m_fScaleY,
									     x,	y );
	
	return m_sTransform;
}

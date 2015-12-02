#include "Parameters.h"

using namespace std;
using namespace ai::query::request;

Parameters::Parameters(std::string sessionId,
                       bool resetContexts,
                       std::shared_ptr<std::string> timeZone,
                       std::vector<std::string> contexts,
                       std::vector<Entity> entities
                       ):
    sessionId(sessionId), resetContexts(resetContexts), timeZone(timeZone), contexts(contexts), entities(entities)
{
    if (sessionId.size() == 0) {
        throw invalid_argument("SessionId connot be zero length.");
    }
}

Parameters& Parameters::setResetContexts(bool resetContexts)
{
    this->resetContexts = resetContexts;
    return *this;
}

Parameters& Parameters::setTimeZone(std::shared_ptr<std::string> timeZone)
{
    this->timeZone = timeZone;
    return *this;
}

Parameters& Parameters::addContext(std::string context)
{
    this->contexts.push_back(context);
    return *this;
}

Parameters& Parameters::addEntity(Entity entity)
{
    this->entities.push_back(entity);
    return *this;
}

bool Parameters::getResetContexts() const
{
    return resetContexts;
}

std::string Parameters::getSessionId() const
{
    return sessionId;
}

std::shared_ptr<std::string> Parameters::getTimeZone() const
{
    return timeZone;
}

std::vector<std::string> Parameters::getContexts() const
{
    return contexts;
}

std::vector<Entity> Parameters::getEntities() const
{
    return entities;
}
